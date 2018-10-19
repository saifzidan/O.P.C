create database OPC
create table storage (id int primary key identity (1,1) , ultrasonicFK int , rightmotorFK int , leftmotorFK int )
create table ultrasonic (id int primary key identity (1,1) , ultrasonic float)
create table [right] (id int primary key identity (1,1) ,speed float)
create table [left] (id int primary key identity (1,1) ,speed float)

