* In relational model, we can't find two identical rows
* the key is an information that identifies an entity (relation/table)
* we can't find two entities with the same key
* keys have several categories, an important type of keys is primary key
* Primary key is the minimum of attributes which identify an entity
* why to use composite keys? because one attribute may not be able to uniquely identify an entity
* A student may have several condidate keys: ID, NSS, NID, BID why do we have to add an ID, because other key condidates may be random (the gap between each two instances may be very large), yet when we create a new ID, we will take into consideration the population and the number of people in the population .... Additionaly, other IDs are managed by other structures, yet if a change has occured from other structures, we'll be required to change our IDs accordingly. One more benefit of using our custom ID,
* NOTE: THE ID should contain information about the instance
* It's better to use keys with one attribute rather than composite keys
* We can use autoincrement to set IDs
* The ID SHOULD better be in numerical format because 1 has only one potential representation, also it would be very easy to search and retrieve a record (row). The search for numerical values is much more faster than alphanumerical
* alphanumerical format was used in the first generation of databases
* Condidate keys that are not PRIMARY are SECONDARY keys
* HOW TO COMMUNICATE THIS WITH THE DBMS:
  * constraint  primaryKey(ID) => unique and not null values
  * constraint  u_NSS unique(NSS) => will generate an error if the NSS attribute is not unique
* If you want to leave a data empty for a specific instance, you can put NULL which basically means missing data or no data for that instance
* By default, any attribute we create can take NULL values
* NOT NULL:
  * Yet, if we wanted the attribute we create not to have null values we specify that with the not NULL keyword, thus the DBMS will check if there is a NULL value, also it will check if the type matches or does not match
* What happens if we set NOT Null: IT WILL go to the metadata where there is a constraint table, ...to be continued
* If we don't provide a name for the constraint, the system will choose the name for the constraint, thus it would be very hard to manahe it later, as a solution you should use the syntax specified previously, that is:
  * constraint   primaryKey (ID) => giving a custom name to be able to exploit it later
* Superkey is a composite key 
* primary key is the minimum superkey (prilmayr key is the non reductable superkey)
* we can find primary key as a composite key
* difference between superkey and primary key: we can find a part of superkey as a primary key, superkey is larger (wider) than primary key
* A part of management rules have a direct effect on the model (conceptual model)
* The other part of management rules will transform to constraints
* why we add links? remember the lab1. How to add links in relational model: links are achieved through the use of data (common data over different relations)
* The link needs to be achieved through primary keys. it's a must
* the primary key is considered as foreign key for other tables
* If we have the ID of an instance, we can retireve them all (all the data)
* We have to give it a constraint:
  constraint fk_st_field(foreign key student field) => to this extent the DBMS only know the name of the constraint
  THen;
  constraint fk_st_field foreign key(field) references Field(ID);
  here we are telling the DBMS that the field attribute in our second table is a foreign key its values are all taken from the ID attribute of the **Field** table
* This will cause the DBSM to check wether the foreign key is a primary key for the first table.
* the DBMS will insert a new row in the constraints table of the metadata
* in the metadata contains a constraints table, it will give it a unique ID, gives it a type(foreign key), the table contains the source and destination, then it will fill in the source and destination cells
* Also the DBMS will check if every value of the foreign key corresponds to some value in the first tbale
* There are custom triggers to add some constraints because the system trigger meet all our needs, remember the example of a manager's salary that can't be larger than the salary of their employees, thus it will allow us to creaet personalized constraints
* An example of the use cases of triggers is the number of students, where it increments whenever we add a new student and decrements whenever we delete one
* triggers allow you to deal with data in the database level
* Il faut gerer les donnees a base de la base de donnees et dans le niveau de l'application
* why the previous thing is very important is that because of security issues as well as a better end-user experience
* Algebraic languages: is a logical language 
* The human needs are in natural language however dbms language uses SQL language
* SELECT IS USED TO retrieve a subset of the rows, &sigma; all the rows with all the attributes