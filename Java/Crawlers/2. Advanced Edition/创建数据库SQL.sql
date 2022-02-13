-- 主表
create table school (
	sid int PRIMARY key auto_increment comment 'id',
	sname VARCHAR(10) comment '学校名',
	recruitment LONGTEXT comment '招生简章',
	csid int COMMENT '链接专业表的id',
	tid int comment '链接导师id',
	aid int comment '链接帖子id',
	FOREIGN key(csid) REFERENCES cs(csid)
);

-- 专业信息
create table cs(
	csid int PRIMARY key auto_increment comment 'csid',
	collegecode VARCHAR(10) comment '学院代码',
	collegename varchar(20) comment '学院名称',
	professioncode varchar(10) COMMENT '专业代码',
	professionname varchar(10) COMMENT '专业名称',
	studyway varchar(10) COMMENT '学习方式',
	degreetype varchar(10) COMMENT '学位类型',
	sum int comment '复试总分',
	sum100 int comment '复试100',
	morethan100 int comment '复试>100'
);

-- 导师的信息
CREATE table teachers(
	id int PRIMARY key auto_increment comment 'id',
	tid int comment '链接导师id',
	tname VARCHAR(100) comment '导师姓名',
    tURL text comment '导师主页',
	tphonenumber varchar(20) comment '电话',
	tfax varchar(20) COMMENT '传真',
	temail varchar(30) comment 'E-mail',
	studydir varchar(100) comment '研究和教学方向',
	eduresume text comment '教育简历',
	proresume text comment '专业履历'
);

-- 官方的一些文章
create table articles(
	id int PRIMARY key auto_increment comment 'id',
	aid int comment '与主表链接的aid',
	title varchar(100) comment '帖子标题',
	content LONGTEXT comment '内容'
);
