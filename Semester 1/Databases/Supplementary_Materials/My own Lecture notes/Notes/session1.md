* The hierarchy of data contains three different levels:
  * Knowledge
  * Information
  * Data
* When data is analyzed or being treated, it becomes information
* The difference between data and information, is that data does not have a meaning compared to information
* Knowledge is a lot of information
* For example AI algorithms are designed to take data as input and to make knowledge out of it
* If we store data in the files, many problems will be generated, , for example: each time when we want to perform file processing, we need to write a corresponding program for that, the probelm here is we wanted to enable even non programmers to access data and manipulate it. An other problem is that we can't make relationships between different files because the OS is the only thing responsible for these things and you cannot make inistructions for the OS to control data. An other issue iws with security there absolutely solutions for that but they take so much time and they are very costly that is why we thought about databases
* We can also use Excel, but there are many problems involved too. First, duplicating (copying) file => redunduncy, an other problem is that we can't make information between different excel files, and also it's error prone, +security issues (someone can see any data which does not matter for them)
<aside>
The OS is the only thing which can access files in the system because the OS has its own structure of it, if one Byte changes, all the data will be meaningless. The OS can be considered as a warehouse owner.
</aside>

# What are databases?
* Data bases are shared(many people can work sumiltaneously), integrated computer structure that stores a collection of:(two databases)
  * End-user data: raw facts of interest to end user
  * Metadata: data about data that is:
    * Providing description of data characteristics and relationships in data
    * Complements(restrictions on accessing files) and expands values or data
* Database management system (DBMS): are collection of programs which:
  * Manage structure and controls access to data
  * gives meaning to the data
  * Manage the consistency and coherence of databases (correct and exact data)
* Advantages of the DBMS:
  * Improved Sharning data
  * Improved data security
  * Better data integration
  * Minimize the data inconsistency
  * Improved data access
  * Improved decision making
  * Increased end-user productivity
<aside>
DBMS checks the validity of the data when an event occurs (an event occurs when we attempt )
data is not the property of DBMS, it's the property of users
DBMS acts as an intermidiate between the database and the DBA
DBMS checks the privileges of the user to perform some operations
The DBMS can't delete data that is linked to other datan to be able to delete the first data you first should delete the links then delete the data
DBMS is the first line defense
The OS is the low level line for managing data, the DBMS passes instructions to the OS

</aside>

## Models of databases:
### Hierarchical:(hierarchical structure)
### Network model
The difference between hierarchical model and network model is that in the network model allows a child node to have multiple parent node, however the hierarchical model does not

* CODD HAS COME UP WITH RELATIONAL MODEL IS BEING USED FOR LONG TIME BC IT'S SOLID THIS IS BECAUSE   IT'S BASED ON MATHEMATICAL FOUNdations such as: theory of sets
* Relational DBs are made up of tables columns are known as attributes or properties, lines are known as *tuples*, record, or instances or objects (compound records, objects)
* relational DBs are known as logical models, logical models suppose that all the models are made up of tables
* It's difficult to communicate with clients using logical models, instead it's better to use conceptual modesl}}
* COnceptual models contain concpts  
* Physical models are used by OS
