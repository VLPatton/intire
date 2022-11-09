# Intire
Intire is a managed inventory system that has a goal of working with a QR code reader to keep tabs on items. Originally designed b/c I wanted to make sure no one was breaking/stealing/etc my stuff.
## Release Version
None
## Debug Version
0.0.2-rc0
## Completed Tasks
* Read JSON file using `nlohmann::json`
* Print IDs within a Category class with proper formatting according to the Category's template object
* Ability to execute tasks based on CLI switches
## TODO
* Implement CLI functionality
    - `-a | --add`
    - `-s | --with-scanner`
    - `-r | --remove`
    - `-e | --edit`
    - `-l | --list [file]`
* Implement scanner functionality
