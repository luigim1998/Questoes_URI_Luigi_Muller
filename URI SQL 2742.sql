--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2742

CREATE TABLE dimensions(
	id INTEGER PRIMARY KEY,
	name varchar(255)
);

CREATE TABLE life_registry(
	id INTEGER PRIMARY KEY,
	name VARCHAR(255),
	omega NUMERIC,
	dimensions_id INTEGER REFERENCES dimensions (id)
);


INSERT INTO dimensions(id, name)
VALUES 
      (1, 'C774'),
      (2, 'C784'),
      (3, 'C794'),
      (4, 'C824'),
      (5, 'C875');
      
INSERT INTO life_registry(id, name, omega, dimensions_id)
VALUES
	  (1, 'Richard Postman', 5.6, 2),	
	  (2, 'Simple Jelly', 1.4, 1),	
	  (3, 'Richard Gran Master', 2.5, 1),	
	  (4, 'Richard Turing', 6.4, 4),	
	  (5, 'Richard Strall',	1.0, 3);

SELECT life_registry.name, round(life_registry.omega*1.618, 3)
FROM life_registry INNER JOIN dimensions 
ON life_registry.dimensions_id = dimensions.id 
    AND (dimensions.name = 'C875' OR dimensions.name = 'C774')
    AND life_registry.name LIKE 'Richard%' ORDER BY life_registry.omega;
  
  /*  Execute this query to drop the tables */
  -- DROP TABLE life_registry, dimensions; --
