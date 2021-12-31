
#include "DatabaseEnv.h"
#include "ScriptMgr.h"
#include "Player.h"

uint32 SPELL = 0;

class cast_spell_on_player_for_mapid_in_phaseid : public PlayerScript
{
public:
    cast_spell_on_player_for_mapid_in_phaseid() : PlayerScript("cast_spell_on_player_for_mapid_in_phaseid") {}

    void OnMapChanged(Player* player)
    {
        QueryResult result = WorldDatabase.PQuery("SELECT `phaseId`, `spellId` FROM `cast_spell_on_player_for_mapid_in_phaseid` WHERE `mapId` = %u", player->GetMapId());
        if (result)
        {
            Field* fields  = result->Fetch();
            uint32 phaseId = fields[0].GetUInt32();
            int32  spellId = fields[1].GetUInt32();
            
            if (player->GetPhaseMask() == phaseId)
            player->CastSpell(player, spellId, true);
            /*
            if (player->GetMapId() == map && player->GetPhaseMask() == phaseId)
                player->CastSpell(player, spellId, true);
            */
            SPELL = spellId;

          
        }
        else
        {
            if (SPELL > 0)
            {
                player->RemoveAurasDueToSpell(SPELL);
                SPELL = 0;
            }
        }
        
    }

};

void AddPhase_AuraScripts()
{
    new cast_spell_on_player_for_mapid_in_phaseid();
}
