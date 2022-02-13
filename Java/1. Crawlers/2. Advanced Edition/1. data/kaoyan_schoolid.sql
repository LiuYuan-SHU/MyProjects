-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: localhost    Database: kaoyan
-- ------------------------------------------------------
-- Server version	8.0.26

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `schoolid`
--

DROP TABLE IF EXISTS `schoolid`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `schoolid` (
  `idOfURL` varchar(10) DEFAULT NULL COMMENT '网页中学校对应的id',
  `name` varchar(20) DEFAULT NULL COMMENT '学校名称'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `schoolid`
--

LOCK TABLES `schoolid` WRITE;
/*!40000 ALTER TABLE `schoolid` DISABLE KEYS */;
INSERT INTO `schoolid` VALUES ('82','北京大学'),('83','中国人民大学'),('84','清华大学'),('87','北京航空航天大学'),('88','北京理工大学'),('97','中国农业大学'),('103','北京师范大学'),('301','南开大学'),('302','天津大学'),('703','大连理工大学'),('707','东北大学'),('242','吉林大学'),('829','哈尔滨工业大学'),('2','复旦大学'),('3','同济大学'),('4','上海交通大学'),('454','南京大学'),('456','东南大学'),('571','浙江大学'),('330','中国科学技术大学'),('679','厦门大学'),('350','山东大学'),('593','武汉大学'),('594','华中科技大学'),('646','湖南大学'),('647','中南大学'),('397','中山大学'),('400','华南理工大学'),('750','重庆大学'),('263','四川大学'),('265','电子科技大学'),('767','西安交通大学'),('768','西北工业大学'),('662','兰州大学');
/*!40000 ALTER TABLE `schoolid` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-01-11 21:22:56
