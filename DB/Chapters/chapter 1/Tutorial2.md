# Chapter 2: Data Models
## Chapter outline:
* Discuss the different data models and why data modeling is important
* Describe the basic data-modeling building blocks
* Define what business rules are and how they influence database design
* Understand how the major data models evolved
* List emerging alternative data models and the needs they fulfill
* Explain how data models can be classified by their level of abstraction

## Data modeling and data models:
* Data modeling is the first step in designing a database, it refers to the process of creating a specific data model for a determined problem domain, a data model is a relatively simple representation of more complex real world data structures
* The model's main function is to help you understand the complexities of the real world environment. Within a database environment, a data model represents data structures and their characteristics, relations, contraints, transformations, and other constructs with the purpose of supporting a specific problem domain 
* Note: the term data model and database model are used interchangeably, in this chapter we will use to database model to refer to the implementation of a data model within a specific database system 
* Data modeling is an iterative, progressive process, where you start with a simple understanding of the problem domain, and as your understanding increases, so does the level of details in the data model. When done properly, the final data model is a blueprint with all the instructions to build a database that will meet all the user's requirements
* Note: an implementation-ready data model should contain at least the folllowing components:
  * A description of the data structure that will store the end-user data
  * A set of enforceable rules to guarantee the integrity of data
  * A data manipulation methodology to support the real-world data transformations

## The importance of data models:
* Data models can facilitate interaction among the designer, the applications programmer and the end user. In short, data models are a communication tool between the designer, the applications programmer and the end user as each have their own view of data
* When a good database blueprint is available, it does not matter that an applications
programmer’s view of the data is different from that of the manager or the end user.
* Keep in mind that a house blueprint is an abstraction, you can not live in the blueprint. Similarly, the data model is an abstraction, you can not draw the required data out of the data model
* Just as you are not likely to build a good house without a blueprint, you are equally unlikely to create a good database without first creating an appropriate data model.

## Data model basic building blocks:
* The basic building blocks of all data models are **entities**, **attributes**, **relationships**, and **constraints**.
* An entity represents a particular type of object in the real world, meaning that the entity is distinguishable, that is each entity occurrence is unique and distinct
* An attribute is a characteristic of an entity, for example, a CUSTOMER entity would be described by attributes such as customer last name, customer first name, customer address ...
* A relationship describes an association among entities. For example, a relationship
exists between customers and agents that can be described as follows: an agent can serve
many customers, and each customer may be served by one agent. Data models use three types of relationships: one-to-many 1:M or 1..*, many-to-many M:N or *..* and one-to-one 1:1 or 1..1
  * One-to-many relationship: 1:M or 1..* a painter creates many different paintings but each is painted by only one painter, thus the painter (the one) is related to the paintings (the many), therefore database designers label the relationship (PAINTER paints PAINTINGS) as 1:M (notice that entity names are written in uppercase, so they are easily identified)
  * Many-To-Many relationship M:N or *..*: an employee may learn many job skills, and each job skill may be learned by many employees, thus the db designers have labeled the relationship "EMPLOYEE learns SKILL" as M:N
  * One-To-One relationship: A retail company's management structure may require each employee to manage one single store, in turn, each store manager who is an employee manages only one store. Therefore, the relationship "EMPLOYEE manages STORE" is labeled as 1:1
Note: the preceding discussion identified each relationship in both directions, that is the relationships are bidirectional
* A constraint is a restriction placed on the data, they are significantly important because they help to ensure data integrity, constraints are normally expressed in the form of rules, examples include:
  * An employee's salary must have values between 6000 and 350000
  * Each class must have one and only one teacher...

Now how to identify the different building blocks of a data model, first we should identify the business rules for the problem domain you are modeling
<business rules ... to be continued>

### The evolution of data models:
1. Hierarchical and Network Models: 
was developed in the 1960s to manage large amounts of data for complex manufacturing projects. The model's basic logical structure is represented by an upside-down tree. The hierarchical structure contains levels or segments. A segment is the equivalent of a file system's record type. The hierarchical model depicts a set of one-to-many (1:M) relationships between a parent and its children segments. meaning that each parent can have many children but a child has only one parent
2. The network model: was created to represent complex data relationships effectively than the hierarchical model. The network model uses M:N relationships, meaning that one parent can have many children and one child may have many parents. 
<aside>
Here are some terminologies:
* Schema: is the conceptual organization of the entire database 
* Subschema: defines the portion of the database seen by the application programs
* Data manipulation language (DML) is the environment in which data can be managed and is used to work with the data in the database
* Data definition language: enables the database administrator to define the schema components
</aside>

3. The relational model: The relational model was introduced in 1970, the relational model is based on a mathematical set of theory and represents data as independent relations. Each relation (table) is conceptually represented as a two-dimensional structure of intersecting rows and columns. Each row in a relation is called a tuple, each column represents an attribute The relations are related to each other through the sharing of common entity characteristics (values in columns)
The relational data model is implemented through a very sofisticated **relational database management system (RDBMS)**. The RDBMS performs the same basic functions provided by the hierarchical and network DBMS systems, in addition to a host of other functions which make the relational model easier to understand and implement. Arguably, the most important advantage of the RDBMS is its ability to hide the complexities of the relational model from the user. The RDBMS manages all of the physical details, while the user sees the relational database as a collection of tables in which data is stored. Thus, the user can query and manipulate data in a way that seems logical and intuitive
* How are tables related to each other in a relational model?  => tables are related to each other through the sharing of a common attribute (a value in a column). For example (student ID from the TD)
* The relational model provides a minimum level of controlled **redundancy** to eliminate most of the redundancies commonly found in file systems
* The relationship type (1:M, 1:1, or M:N) is often shown in a relational schema. A relational diagram is a representation of the relational database's entities, the attributes of those entities, and the relationships between them, below is an example of a relational diagram:
![](photos/relational%20diagram.png)
* One reason why relational data models rise to dominance is its powerful and flexible query language. Most relational database software uses structured query language (SQL)which allows for better and easier user queries. SQL makes it possible to retrieve data with far less effort than any other database or file environment
* Any SQL based relational database application involves three parts: a user interface, a set of tables stored in the database, and the SQL engine(hidden from the user, it executes all queries or data requests, it's a part of the DBMS software. The SQL engine processes all user requests—largely behind the
scenes and without the end user’s knowledge. Hence, SQL is said to be a declarative language that tells what must be done but not how)