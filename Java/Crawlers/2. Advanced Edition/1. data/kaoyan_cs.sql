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
-- Table structure for table `cs`
--

DROP TABLE IF EXISTS `cs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cs` (
  `csid` int NOT NULL AUTO_INCREMENT COMMENT 'csid',
  `collegecode` varchar(10) DEFAULT NULL COMMENT '学院代码',
  `collegename` varchar(20) DEFAULT NULL COMMENT '学院名称',
  `professioncode` varchar(10) DEFAULT NULL COMMENT '专业代码',
  `professionname` varchar(10) DEFAULT NULL COMMENT '专业名称',
  `studyway` varchar(10) DEFAULT NULL COMMENT '学习方式',
  `degreetype` varchar(10) DEFAULT NULL COMMENT '学位类型',
  `articleURL` text COMMENT '官网文件链接',
  `politic` text COMMENT '政治分数',
  `english` text COMMENT '英语分数',
  `professional_subject1` text COMMENT '专业课1分数',
  `professional_subject2` text COMMENT '专业课2分数',
  `total` text COMMENT '总分',
  `schoolid` int DEFAULT NULL COMMENT '学校id',
  PRIMARY KEY (`csid`)
) ENGINE=InnoDB AUTO_INCREMENT=62 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cs`
--

LOCK TABLES `cs` WRITE;
/*!40000 ALTER TABLE `cs` DISABLE KEYS */;
INSERT INTO `cs` VALUES (1,NULL,'清华大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434845.html','50','50','80','70','310',84),(2,NULL,'上海交通大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434853.html','55','55','80','85','330',4),(3,NULL,'上海交通大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434853.html','55','55','80','85','330',4),(4,NULL,'哈尔滨工业大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434877.html','50','45','80','80','320',829),(5,NULL,'中国人民大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434880.html','50','50','90','90','330',83),(6,NULL,'中国人民大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434880.html','40','40','80','80','280',83),(7,NULL,'中山大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210312/2037434885.html','50','50','60','60','280',397),(8,NULL,'中国农业大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435032.html','50','50','80','80','305',97),(9,NULL,'中国农业大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435032.html','50','50','85','85','305',97),(10,NULL,'同济大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435035.html','50','50','80','75','310',3),(11,NULL,'同济大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435035.html','50','50','80','75','310',3),(12,NULL,'浙江大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435041.html','55','55','85','85','330',571),(13,NULL,'兰州大学',NULL,'计算机科学与技术','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435061.html','45','45','75','75','290',662),(14,NULL,'兰州大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435061.html','45','45','70','70','295',662),(15,NULL,'北京大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435064.html','55','55','90','90','310',82),(16,NULL,'北京大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435064.html','55','55','90','90','300',82),(17,NULL,'北京师范大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435071.html','48','48','70','90','300',103),(18,NULL,'南开大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435072.html','50','45','75','75','290',301),(19,NULL,'东北大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435075.html','45','45','70','70','310',707),(20,NULL,'东北大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435075.html','45','45','70','70','310',707),(21,NULL,'大连理工大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435083.html','45','45','70','75','300',703),(22,NULL,'大连理工大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435083.html','45','45','70','75','300',703),(23,NULL,'天津大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435103.html','50','50','75','80','320',302),(24,NULL,'天津大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435103.html','50','50','75','80','320',302),(25,NULL,'厦门大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435107.html','50','45','70','70','310',679),(26,NULL,'厦门大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435107.html','50','50','75','75','320',679),(27,NULL,'中国科学技术大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435108.html','50','45','70','70','310',330),(28,NULL,'吉林大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435111.html','45','45','68','90','300',242),(29,NULL,'华南理工大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210313/2037435112.html','50','50','70','70','310',400),(30,NULL,'北京航空航天大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037633179.html','40','40','60','60','310',87),(31,NULL,'北京航空航天大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037633179.html','40','40','60','60','300',87),(32,NULL,'西北工业大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037612494.html','50','50','70','70','315',768),(33,NULL,'东南大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037612513.html','50','50','70','70','310',456),(34,NULL,'东南大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037612513.html','50','50','70','70','310',456),(35,NULL,'四川大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037798759.html','45','45','68','68','310',263),(36,NULL,'四川大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037798759.html','53','53','80','80','335',263),(37,NULL,'山东大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037803240.html','50','50','75','75','320',350),(38,NULL,'山东大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037803240.html','50','50','75','75','320',350),(39,NULL,'西安交通大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037842424.html','50','50','85','85','330',767),(40,NULL,'西安交通大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210315/2037842424.html','50','50','90','85','330',767),(41,NULL,'电子科技大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028377.html','45','45','68','68','310',265),(42,NULL,'电子科技大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028377.html','45','45','68','68','280',265),(43,NULL,'重庆大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028378.html','50','50','75','75','320',750),(44,NULL,'重庆大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028378.html','50','50','75','75','320',750),(45,NULL,'湖南大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028388.html','50','50','80','80','310',646),(46,NULL,'湖南大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038028388.html','45','45','70','70','290',646),(47,NULL,'复旦大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038352059.html','50','50','70','70','300',2),(48,NULL,'复旦大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210316/2038352059.html','50','50','70','70','320',2),(49,NULL,'中南大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210317/2038676712.html','50','50','80','80','320',647),(50,NULL,'中南大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210317/2038676712.html','50','50','80','80','320',647),(51,NULL,'北京理工大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210317/2038739090.html','50','50','75','75','320',88),(52,NULL,'北京理工大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210317/2038739090.html','45','45','70','70','300',88),(53,NULL,'南京大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210318/2039088387.html','50','50','75','75','300',454),(54,NULL,'南京大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210318/2039088387.html','50','50','75','75','290',454),(55,NULL,'华中科技大学',NULL,'工学','全日制','学硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210319/2039513642.html','50','50','70','70','300',594),(56,NULL,'华中科技大学',NULL,'电子信息','全日制','专硕','https://yz.chsi.com.cn/kyzx/fsfsx34/202103/20210319/2039513642.html','50','50','70','70','300',594),(57,NULL,'武汉大学',NULL,'计算机','全日制','学硕','https://gs.whu.edu.cn/info/1056/8083.htm','50','50','80','80','355',593),(58,NULL,'武汉大学',NULL,'软件工程','全日制','学硕','https://gs.whu.edu.cn/info/1056/8083.htm','50','50','80','80','335',593),(59,NULL,'武汉大学',NULL,'电子信息','全日制','专硕','https://gs.whu.edu.cn/info/1056/8083.htm','50','55','80','80','365',593),(60,NULL,'武汉大学',NULL,'网络空间安全','全日制','学硕','https://gs.whu.edu.cn/info/1056/8083.htm','55','50','80','85','330',593),(61,NULL,'武汉大学',NULL,'电子信息','全日制','专硕','https://gs.whu.edu.cn/info/1056/8083.htm','50','40','65','60','275',593);
/*!40000 ALTER TABLE `cs` ENABLE KEYS */;
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
