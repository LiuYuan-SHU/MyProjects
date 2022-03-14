create table books(
	id int primary key auto_increment,
    name varchar(20),
    url varchar(100),
    author varchar(20),
    style varchar(10),
    finished varchar(10),
    updateTime varchar(50),
    bookIntro text
);
select * from books;
delete from books;
ALTER table books AUTO_INCREMENT 1;
