# Chapter One: Database Systems
## Chapter's Outline:
* Define the difference between data and information
* Describe what a **database** is, its different types and why is it important
* Explain the importance of database design 
* See how databases evolved from file systems
* Understand flaws in file system data management
* Outline the main components the database system...
## 1. Why databases:
* Data is used by organizations to keep track of their day-to-day operations. Such data is used to generate information, which in turn is the basis of good decisions, databases are involved in almost all facets and activities of our daily lives: school, work, medical care, nonprofit organizations...
* Databases evolved from the need to manage large amounts of data in an organized and efficient manner. In early days computer file systems was used to organize such data. Yet, file systems have some drawbacks and limitations:
  * Require knowledge about programming
  * Security issues
  * Redundancy (different versions of data are stored with different contents)
  * Limitations to access and modify the content of files because they're managed by the OS...
* In today's world, data is ubiquitous (global, everywhere) and pervasive(unescapable, persistent), from birth to death we generate and consume huge amount of data, databases make data persistent and shareable in a secure way
* Data are also cruicial for businesses to survive and prosper as they need to keep data related to their customers, their employees, their goods, how they owe money...
* Databases are specialized structures that allow computer-based systems to **store**, **modify**, **access**, and **retrieve** data easily and very quickly

## Data Versus Information:
* Data consists of raw facts (the raw word indicates that the facts have not been processed yet to reveal their meaning)
* Information is the result of processing raw data to reveal its meaning. Information consists of transformed data and facilitates decision making
* To reveal meaning, information requires context
* Information is used to reveal the meaning of data
* Data are building blocks of information
* Knowledge is a hidden information, knowledge implies understanding of the information as it applies in the environment
* New knowledge can be derived from old knowledge
* Knowledge and information require timely and accurate data. Such data must be properly generated and stored in a format that is easy to access and process. In addition, like any basic resource, the data environment must be managed carefully
## What is a database?
* Data managment is the process that focusses on data collection, storage, and retrieval. Common data managment functions include addition, modification, and listing
* A database is a shared, integrated computer structure that houses a collection of related data. It contains two types of data:
  * End-user data (raw facts of interest to the end user)
  * Metadata (data about data, that is data about data characteristics and relationships through which end-user data is integrated and manged). The metadata contains information that complements and expands the value and use of data, it presents a more complete picture of the data in the database. Hence the label of database as :collection of **self-describing** data
* Database Managment System: DBMS is a collection of programs that manages the database structure and controls access to the data within the database.A Database Management. It is a software that provides an interface for interacting with a database. It facilitates the creation, retrieval, update, and management of data in the database. Essentially, a DBMS acts as an intermediary between the user, applications, and the database itself
## Roles and advantages of the DBMS:
* The DBMS serves as the intermediary between the user and the database. The database itself is stored as a collection of files, and the only way to access data within these files is through the DBMS
* The DBMS enables the data in the database to be shared efficiently among multiple applications or users. Such access makes it possible
for end users to respond quickly to changes in their environment.
* Improved data sharing: a DBMS provides a framework for better enforcement of data privacy and security policies.
* Improved data security: the DBMS provides a framework for better enforcement of data privacy and security policies
* Better data integration: wider access to well-managed data promotes an integrated view of the organization's operations and clearer view of the big picture
* Minimized data inconsistency: data inconsistency exists when different versions of the same data yield different (inconsistent) results, an example of data inconsistency occurs when the company’s regional sales office shows the price
of a product as $45.95 and its national sales office shows the same product’s price
as $43.95.
* Improved data access: The DBMS makes it possible to produce quick answers to ad hoc queries (An ad hoc query is used to get specific information from a database when the need arises, as opposed to standard queries that are predefined and processed on a regular, recurring basis.). The DBMS sends back an answer (called query result set) to the application
* Improved decision making: better-managed data and improved data access make it possible to generate better-quality information, on which better decisions are based. Data quality is a comprehensive approach to promoting the accuracy and validity and timliness of data
## Types of databases:
* Databases can be classified based on different standards:
  * The number of users supported: determines whether the database is classified as single-user or multiuser. A single-user database supports only one user at a time. In other words, if
  user A is using the database, users B and C must wait until user A is done. A single user database that runs on a desktop is called **desktop database**. A multiuser database supports multiple users at the same time(it's either called workgroup databse for small number of users or enterprise database for larger number of users)
  * The location: determines whether the database is centralized database that supports data located at a single site, and distributed database that supports data distributed accross several different sites 
  * A cloud database is a database that is created and maintained using cloud data services such as Microsoft Azure or Amazon AWS. The data owners don't have to know, or be concerned about the hardware, and software that are used to support their databases, did not have to buy, install, configure, or maintain any hardware, operating systems, or network devices. It simply purchased storage and processing capacity for its data and applications.
  * The type of data stored in the database: determines whether the database is general-purpose database or discipline-specific database (specific subjects, academic, research purposes)
  * The time sensivity of the data stored in the database: to determine whether a database is operational(a.k.a online transactional  database, Online Transaction Processing (OLTP), or production database) that stores an enterprise day-to-day operations and data, and analytical database (which stores historical data and business metrics used for tactical or strategic decision making). Typically, analytical databases comprise two main components: a data warehouse and an online analytical processing front end. The data warehouse is a specialized database which stores data in a format optimized for decision support. From the other hand, online analytical processing (OLAP) is a set of tools that work together to provide an advanced data analysis environment for retrieving, processing, and modelling data
  * The degree to which data is structured: to determine whether a database contains **unstructured data**  that is data existing in its original(raw) state in the format in which it was collected, and **structured data** that is the result of formatting unstructured data to facilitate manipulating these data, or even **semi structured** which represents most data you encounter.  Semi structured data has already been processed to some extent 
  Unstructured and semi structured data storage and management needs are being addressed through a new generation of databases known as XML databases(Extensible Markup Language) that is a special language used to represent and manipulate data elements in a textual format. An XML database supports the storage and management of semistructured XML data. Unlike other markup languages, XML permits the manipulation of a document’s data elements
<aside>
Facebook faces many storage challenges. With over 500 terabytes of data coming
in each day, it stores over 100 petabytes of data in a single data storage file system. These exponential amounts of data require the use of specialized databases known as Not-Only SQL databases or NO-SQL databases. The term NoSQL usually refers to the new generation of DBMS that is not based on the traditional relational database model
</aside>

### Why databases design is important:
* Database design refers to the process that yields the description of the database structure and determines the database components. In fact, database design is such a crucial aspect of working with databases. Even a good DBMS will perform poorly with a badly designed database
* Consider the following poor database design:
![poor database design](./Photos/Poor%20db%20design.png)
* Based on this storage of the data, notice the following problems:
• It would be difficult, if not impossible, to produce an alphabetical listing of employ-
ees based on their last names.
database design
The process that yields
the description of the
database structure
and determines the
database components.
The second phase of the
database life cycle.
• To determine how many employees are certified in Basic Database Manipulation,
you would need a program that counts the number of those certifications recorded in
Skill1 and places it in a variable. Then the count of those certifications in Skill2 could
be calculated and added to the variable. Finally, the count of those certifications in
Skill3 could be calculated and added to the variable to produce the total.
• If you redundantly store the name of a skill with each employee who is certified in
that skill, you run the risk of spelling the name differently for different e­ mployees. For
example, the skill Basic Database Manipulation is also entered as Basic DB Manipula-
tion for at least one employee in Figure 1.5, which makes it difficult to get an accurate
count of employees who have the certification.
• The structure of the database will have to be changed by adding more columns to the
table when an employee is certified in a fourth skill. It will have to be modified again
if an employee is certified in a fifth skill.
* In constrast to the previous poor design of the database, consider this efficient design of the database:
![efficient database design](./Photos/Poor%20db%20design.png)

* Proper database design requires the designer to identify precisely the database’s expected use. Designing a transactional database emphasizes accurate and consistent data and operational speed. Designing a data warehouse database emphasizes the use of historical and aggregated data. Designing a database to be used in a centralized,
single-user environment requires a different approach from that used in the design of
a distributed, multiuser database
* Designing appropriate data repositories of integrated information using the two-
dimensional table structures found in most databases is a process of decomposition.
The integrated data must be decomposed properly into its constituent parts, with each part stored in its own table. Further, the relationships between these tables must be carefully considered and implemented so the integrated view of the data can be recreated later as information for the end user.
* A well-designed database facilitates data management and generates accurate and valuable information. 
* A poorly designed database is likely to become a breeding ground for difficult-to-trace errors that may lead to poor decision making—and poor decision making can lead to the failure of an organization.

### Database systems:
* The database system consists of logically related data stored in a single logical repository (the label "logical" reflects the fact that the data repository appears to be a single unit to the end user even though it might be physically distributed among multiple storage locations)
* DBMS makes it possible to eliminate most of the file system's data inconsistency, data anomaly, data dependence, and structural dependence problems. The new generation of DBMS stores not only the data structures but also the relationships between those structures and the access paths to those structures all in a central location. The DBMS is referred to as the database system's heart. However, just like it takes more than a heart to make a human being function, it takes more than the DBMS to make a database system

### The database system environment:
* The database system refers to an organization of components which defines and regulates the storage, collection, management and other data manipulation functionalities. It consists of five major parts:
  * Hardware: all the system's physical devices including computers, storage devices, printers, network devices(including routers and fiber optics) ....
  * Software: three significant softwares:
    * Operating System: manages the hardware components, and makes it possible for all other software to run on the hardware
    * DBMS Software: manages the database within the database system, some examples of DBMS software are Microsoft SQL server, Oracle's Mysql, MySQL, Redis...
    * Application programs(database application) and utility software: Application programs are most commonly used to access data within the database to generate reports, tabulations, and other information in order to facilitate decision making. However, utilities are the software tools used to help manage the computer environment in which data access and manipulation take place.
  * People: this components includes all users of the database system. They fall into five categories, where each user type performs unique and complementary functions:
    * System administrators: oversee the database system's general operations
    * Database Administrators: DBAs manage the DBMS and ensures that the database is working properly
    * Database designers: design the database structure, they are the database architects, because the organizations strive to optimize their data resources, the database designers' responsibilities have expanded to cover new dimensions and growing responsibilities
    * System anlysts and programmers: design and implement the application programs. They design and create the data-entry screens, reports, and procedures through which end users access and manipulate the database's data
    * End users and the people who use the application programs: to run the organization. For example, sales clercks, supervisors, mangers... are all considered as end users
<aside>
The difference between application programs and DBMS: application programs are software designed to perform specific tasks of functions, also, they can interact with databases through APIs (Application Programming Interfaces). REMEMBER! application programs are developped by the analysts and programmers
</aside>

<br>
<aside>
What are procedures? Procedures are the instructions and rules that govern the design and the use of a database system. Procedures play an important role in a company because they enforce the standards by which business is conducted within an organization and with customers
</aside>

#### DBMS Functions:
* DBMS performs several important functions that guarantee an efficient management of data, these functions include:
  * Data dictionary management: data dictionary is a DBMS component that stores metadata that need to be kept by the DBMS, it's a table containing the following columns: data(name of the attribute, for example Title), coding(for example book_title), designation(describing what the data corresponds to, for example title of the book), type(alphanumeric, numeric, alphabetical, boolean, data, for example alphanumeric), size(the maximum possible number of characters, for example 50 character). The DBMS creates a data dictionary and therefore the DBMS uses it to look up the required data component structures and relationships. Additionally, any changes which affect the databse will be automatically recorderd in the data dictionary. In other words, the DBMS provides data abstraction
  * Data storage managment: The DBMS creates and manages the complex structures required for data storage. Data storage management is also important for the database **performance tuning** that is the different activities which make a database perform more efficiently in terms of storage and access speed. Although, the user sees the database as a single data storage unit, the DBMS actually stores the database in multiple physical data files which can be stored in different storage media devices(the DBMS does not have to wait for one disk request to finish before the next one starts)
  * Data transformation and presentation: the DBMS transforms input data to conform to required data structures. That is, the DBMS formats the physically retrieved data to make it conform to the user. For example, imagine an enterprise database used by a multinational company.An end user in England would expect to enter the date July 11, 2017, as “11/07/2017.”In contrast, the same date would be entered in the United States as “07/11/2017.”Regardless of the data presentation format, the DBMS must manage the date in the proper format for each country.
  * Data security management: the DBMS creates a security system that enforces system security and data privacy. Security rules involve controlling access to data stored in the database and controlling which users can perform different operations (add, delete, read, or modify) on the data stored in the database
  * Multiuser access control: to provide integrity and data consistency, the DBMS uses sofisticated algorithms to ensure that multiple users can access the database concurrently without compromising its integrity
  * Backup and Recovery management: the DBMS provides backup and data recovery to ensure data safety and integrity. Recovery management deals with the recovery of the database after a failure, such as
  a bad sector in the disk or a power failure...
  * Data integrity management: the DBMS maximizes data integrity and minimizes data inconsistency through the different management rules
  * Database access languages and APIs: The DBMS provides data access through a query language that is a nonprocedural language(a nonprocedural language is one that lets the user specify what must be done without having to specify how it must be done). Structured Query Language (SQL) is the query language and access standard supported by the majority of DBMS vendors(SQL is a relational database language composed od commands that enable users to create database and table structures, perform manipulations on data, administering data...). The DBMS also provides APIs to procedural languages such as COBOL, C, Java
  * Database communication interfaces: DBMSs accept end-user requests via multiple, different network environments. For example, the DBMS MIGHT provide access to the database via web browsers