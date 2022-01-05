#include "DatabaseEnv.h"
#include "ScriptMgr.h"
#include "Player.h"

class PhasingSystem
{
private:
    PhasingSystem() = default;
public:
    PhasingSystem(PhasingSystem&&) = delete;
    PhasingSystem(const PhasingSystem&) = delete;

    static PhasingSystem* instance()
    {
        static PhasingSystem instance;
        return &instance;   
    }
    std::map<std::pair<uint32, uint32>, uint32> SpellPhaseContainer;
    void LoadPhasingSystem();
};

#define sPhasingSystem PhasingSystem::instance()

void PhasingSystem::LoadPhasingSystem()
{
    auto result = WorldDatabase.Query("SELECT `phaseId`, `mapId`, `spellId` FROM `cast_spell_on_player_for_mapid_in_phaseid`");
    if (!result)
        return;
    do
    {
        auto data = result->Fetch();
        sPhasingSystem->SpellPhaseContainer.insert({ std::make_pair(data[0].GetUInt32(), data[1].GetUInt32()), data[2].GetUInt32() });
    } while (result->NextRow());
}

class cast_spell_on_player_for_mapid_in_phaseid : public PlayerScript
{
public:
    cast_spell_on_player_for_mapid_in_phaseid() : PlayerScript("cast_spell_on_player_for_mapid_in_phaseid") {}

    void OnMapChanged(Player* player)
    {
        auto phaseMapPair = std::make_pair(player->GetPhaseMask(), player->GetMapId());
        if (sPhasingSystem->SpellPhaseContainer.find(phaseMapPair) != sPhasingSystem->SpellPhaseContainer.end())
        {
            auto spellId = sPhasingSystem->SpellPhaseContainer[phaseMapPair];
            player->CastSpell(player, spellId, true);
        }
    }
};

class ws_phasing_system_loader : WorldScript
{
public:
    ws_phasing_system_loader() : WorldScript("ws_phasing_system_loader") {}

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        sPhasingSystem->LoadPhasingSystem();
    }
};

void AddPhase_AuraScripts()
{
    new cast_spell_on_player_for_mapid_in_phaseid();
    new ws_phasing_system_loader();
}
