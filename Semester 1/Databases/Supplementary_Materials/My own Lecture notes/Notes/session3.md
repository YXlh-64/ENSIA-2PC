# Types of databases:
* Centralized dbs: data located at a single site
* distributed dbs: data distributed accross serveral site
* Operational dbs: day-to-day operations, transactional or production database
# Types of databases: (according to the structure)
* Unstructured: data exist in their original state
  It's very complicated to store unstructured data 
  XML allows the programmer to define user-defined tags. To be searched for, xml is generally used in configuration files
* Structured; data result from formatting
* Semistructured: data have been processed to some extent
* Extensible markup language(XML):  
Note: data warehouses are used to generate knowledge*
* filed is data + metadata
* Record is a combination of fields
* a collection of records give us files
DBMS allows us to set our own stucture
conceptual model*******
* Logical independence:
* Physical independence
* Installing a software will allocate a space in memory to store all the programs that come with the software, then it will need configuration files to know how to deal with these programs
* If we want to change some data in a file, the access is gonna be stopped (stop all access because data is being modified)
* DBMS have a lot of software: data recovery, data managment, data storage, it also uses log files...
* All
* Oracle and mySQL dbs are all relational dbs but they are in reality ordbs meaning object relational dbs
* We don't use the ORDBs layer w only use relational dbs
* The problem with relational dbs is scalability (it's very difficult to make a stable system for data), relational dbs are less scalable
* Therefore, administrators were obliged to face redunduncy
* How to store a graph in a relational dbs? it's very complicated, there's a solution that is to get rid of all the links between the nodes of the graph, so there is a lot of data loss, then when we need the graph we'll need to construct the graph once again, that is where NO sequel dbs come into play
* data lack keeping the original format of data, a very important part of data lack is metadata
* ddl => define for sturctures 
* dml => manipulate and store data inside the db
* dql => question the db
* The first thing to do in dbs is creating users admins and identify privileges
* Creating tablespace (like folders) and determine the size
* folders in reality don't have physical memeory locations, they are just interfaces
* If we don't create tablespaces, then the user can take as much space as they want
* The super user in databases is referred to as system
* it's not recommended to use the system mode
* sorting data in dbs is very costly 
* the difference between the primary and temporary tablespace is that the temorary tablespaces are only used for the current session and they disappear once the session is finished
* When using oracle and creating a new user, the user has 0 privileges
* information related to privileges are stored in metadata