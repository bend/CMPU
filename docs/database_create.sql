CREATE DATABASE MUSIC_LIBRARY;
USE MUSIC_LIBRARY;

CREATE TABLE Artist(
	id		INT NOT NULL AUTO_INCREMENT,
	name	TEXT NOT NULL,
	details TEXT,
	PRIMARY KEY	(id)
);

CREATE TABLE Album(
	id		INT NOT NULL AUTO_INCREMENT,
	name	TEXT NOT NULL,
	details TEXT,
	PRIMARY KEY	(id)
);

CREATE TABLE Style(
	id		INT NOT NULL AUTO_INCREMENT,
	name	TEXT NOT NULL,
	details TEXT,
	PRIMARY KEY	(id)
);

CREATE TABLE Song(
	id		 INT NOT NULL AUTO_INCREMENT,
	title	 TEXT NOT NULL,
	duration INT NOT NULL,
	details  TEXT,
	PRIMARY KEY	(id)
);

CREATE TABLE Composed(
	id_artist INT,
	id_album INT,
	FOREIGN KEY(id_artist) REFERENCES Artist(id),
	FOREIGN KEY(id_album)  REFERENCES Album(id),
	year	  INT
);

CREATE TABLE Author(
	id_artist INT,
	id_song INT,
	FOREIGN KEY(id_artist) REFERENCES Artist(id),
	FOREIGN KEY(id_song)   REFERENCES Song(id),
	year 	  INT
);

CREATE TABLE IsIn(
	id_album INT,
	id_song INT,
	FOREIGN KEY(id_album) REFERENCES Album(id),
	FOREIGN KEY(id_song)  REFERENCES Song(id),
	track	 INT
);

CREATE TABLE Got(
	id_style INT,
	id_song INT,
	FOREIGN KEY(id_style) REFERENCES Style(id),
	FOREIGN KEY(id_song)  REFERENCES Song(id)
);
