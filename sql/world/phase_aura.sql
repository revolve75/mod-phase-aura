-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.7.33-log - MySQL Community Server (GPL)
-- Server OS:                    Win64
-- HeidiSQL Version:             11.3.0.6295
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for _acore_world
CREATE DATABASE IF NOT EXISTS `_acore_world` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `_acore_world`;

-- Dumping structure for table _acore_world.cast_spell_on_player_for_mapid_in_phaseid
CREATE TABLE IF NOT EXISTS `cast_spell_on_player_for_mapid_in_phaseid` (
  `phaseId` int(10) unsigned DEFAULT NULL,
  `spellId` int(10) unsigned DEFAULT NULL,
  `mapId` smallint(5) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Storm, your Mythic+ system addition. :)';

-- Dumping data for table _acore_world.cast_spell_on_player_for_mapid_in_phaseid: ~1 rows (approximately)
DELETE FROM `cast_spell_on_player_for_mapid_in_phaseid`;
/*!40000 ALTER TABLE `cast_spell_on_player_for_mapid_in_phaseid` DISABLE KEYS */;
INSERT INTO `cast_spell_on_player_for_mapid_in_phaseid` (`phaseId`, `spellId`, `mapId`) VALUES
	(1, 48066, 576);
/*!40000 ALTER TABLE `cast_spell_on_player_for_mapid_in_phaseid` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
