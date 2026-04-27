# Cli commands Implementation
In order to afford flexibility and simplification we will use command design pattern, which stores in 

`map <String, ICommand* >`

Where  the `key` is a command like *add, recommend, help* and `ICommand*` is a pointer to appropriate `CommandClass`   
