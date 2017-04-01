# Bankir
CLI based banking system management.
Data Structures course project at Telkom University.
Implemented in C++.

## Structures
### Customer
Using double linked list.
Act as the parent of relational list.

### Account
Using double linked list.
Act as the child of relational list.

### List
Using double linked list.
Act as multi-double linked list alias relational list.

## Demo
### Main Program
```
 Bankir 1.0 - Telkom University. Type "help" for more information.

[main]>> help
 Bankir is a CLI based banking system management.
 Keywords: "c" stand for Customer, "a" stand for Account.

 Commands
   help                     Display this message
   info                     Display all customer and their account
   insert [c|a]             Insert new data
   delete [c|a] <id>        Delete data by their ID
   update [c|a] <id>        Update data by their ID
   show   [c|a] <id>        Show data by their ID
   exit                     Close this program

 Examples
   insert c
   This will takes you to the Insert Customer sub-program.

   delete a 2
   This will remove Account with ID 2.

[main]>>
```

### Insert Customer
```
[main]>> insert c

 Attributes
 ----------
 id             Integer    Auto
 age            Integer    Required
 name           String     Required

 Commands
 --------
 save           Save data
 back           Close this interface

[insert| c ]>> age 19
[insert| c ]>> name Wisnu Adi Nurcahyo
[insert| c ]>> id

 => 1

[insert| c ]>> age

 => 19

[insert| c ]>> name

 => "Wisnu Adi Nurcahyo"

[insert| c ]>> save

 Saved! Temporary data removed!

[insert| c ]>>
```

## Clarify
This repository is for educational purpose only.
Don't only copy, modify, and use this as your own work.
Hope this project will help you understanding Data Structures.

## License
Released under the MIT License.