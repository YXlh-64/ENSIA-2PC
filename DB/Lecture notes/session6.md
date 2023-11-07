# &sigma;
* Designers of the database have set a collection of logical operators, which are also called relational operators
* The system is closed: (ferme) All the inputs and ouputs of an operation are tables
* The output is designed to be a table to be able to use the output over again with other logical operators
* For sigma (select) takes as input a table and a set of conditions, the type of condition in this case is Att &theta;(this is boolean) value where &theta; is contained in {<, >, <=, >=, =, !=}
* The relationship between the input table and the output table is that the output is a subtable of the input table
* The schema of the input table and the output table is the same
* There are two special cases where the input table is the same as the output table:
  * all the tuples of the input table verify the condition
  * the condition is always true no matter what the tuple is
* There are also are two special cases where the output table is an empty table:
  * The condition is always false no matter what the tuple is
  * the tuples don't verify the condition
* &sigma; works on rows

# &pi;

* Project has as input a table and as an output a table
* the output is a subset of attributes
* The schema of the input and the output table are not the same
* the input condition must be an attribute inside the table
* We can combine as many operators as we want

## Set operators:
it occurs on rows
* UNION (input two tables, output one table same schema=the same type, the same domain of definition, the condition of the ouput table is that a given tuple belongs to T1 xor belongs to T2)
* If we don't have the same schema 
end of union
* INTERSECT 
* MINUS
* UNION ALL (specific to oracl, it maintains the redundant attributes)
  
## Binary operators:
* JOIN (constructing new tables using links between tables)