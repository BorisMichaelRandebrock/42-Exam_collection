# ExamRank5 - Warlock Spell training C++

In Exam Rank 5, the focus is entirely on cpp classes.     
Don’t feel distressed or overwhelmed by the workload — it is actually not as difficult or time-consuming as it might seem.

All you need to do is stay focused on the task at hand and understand what needs to be done.    
The main challenge is managing the workflow and avoiding confusion over the number of classes. However, most classes are straightforward copies with minor adjustments.

## Overview
The ExamRank5 consists of three consecutive modules designed to build a small system around the concept of a `Warlock` character and its interactions with spells and targets. The modules cover creating and managing classes in C++ using principles of Object-Oriented Programming, following Coplien's form, and focusing on encapsulation, inheritance, and polymorphism. This project has three modules, each progressively building on the last:   

1. **cpp_module00** - The `Warlock` class.    
2. **cpp_module01** - Abstract base classes `ASpell` and `ATarget` with `Fwoosh` and `Dummy` implementations. Warlock class changes for enabling use of the new spell Fwoosh on the target Dummy.    
3. **cpp_module02** - Additional spell and target implementations (Fireball, Polimorph and Brickwall), `SpellBook`, and `TargetGenerator` classes. Warlock changes enabling use of the SpellBook.

## Module Breakdown

### cpp_module00: Warlock Class
In this module, we focus on creating a `Warlock` class. - **Files Required:** `Warlock.hpp`, `Warlock.cpp`    
**Attributes:** Private attributes: `name` (std::string) and `title` (std::string)    
** Constructor: Takes `name` and `title` and outputs a creation message. Destructor: Outputs a message upon destruction.    
- Getters: `getName()` and `getTitle()` returning constant references.    
- Setter: `setTitle(const std::string&)`, allows changing the `title`.   
- `introduce()`: Outputs a message with the `Warlock`'s name and title. The Warlock cannot be instantiated by copy or assignment, ensuring uniqueness and following Coplien’s form.

### cpp_module01: Abstract Spell and Target Classes with Fwoosh and Dummy
This module expands the project by adding the `ASpell` and `ATarget` abstract base classes, along with their first derived classes, `Fwoosh` and `Dummy`.    
**new additional files:** `ASpell.hpp`, `ASpell.cpp`, `ATarget.hpp`, `ATarget.cpp`, `Fwoosh.hpp`, `Fwoosh.cpp`, `Dummy.hpp`, `Dummy.cpp`     
**Classes and Implementation:**  
**ASpell**: Represents spells with  the attributes `name` and `effects`.    
Methods: `getName()`, `getEffects()`, and a virtual `launch()` to define spell behavior.   
**ATarget**: Represents targets with attributes `type` and a virtual `getHitBySpell()` to handle spell interactions.   
**Fwoosh**: Inherits from `ASpell`, representing a simple spell with predefined effects.   
**Dummy**: Inherits from `ATarget`, a target type for basic testing.   
Integrate spells into `Warlock`, enabling spell-usage logic in the `Warlock` class and facilitating interactions with `ATarget`.

### cpp_module02: Additional Spell and Target Classes, SpellBook, and TargetGenerator
In the final module, you create additional implementations of spells and targets, along with `SpellBook` and `TargetGenerator` classes to manage spells and targets.    
**new additional files:** `Fireball.hpp`, `Fireball.cpp`, `Polymorph.hpp`, `Polymorph.cpp`, `Brickwall.hpp`, `Brickwall.cpp`, `SpellBook.hpp`, `SpellBook.cpp`, `TargetGenerator.hpp`, `TargetGenerator.cpp`    
**Classes and Implementation:**    
**Additional Spells and Targets:** **Fireball** and **Polymorph**: New spells inheriting from `ASpell`, each with unique `effects`.    
**Brickwall**: New target inheriting from `ATarget`.    
These 3 are simple repetitions of the previous Fwoosh and Dummy classes.    
BE AWARE OF CHANGING CORRECTLY THE CORRESPONDING MESSAGE, OTHERWISE YOU WILL GET A SEGFAULT.    
**SpellBook**: Manages the collection of spells. Methods: `learnSpell()`, `forgetSpell()`, and `createSpell()`.   
**TargetGenerator**: Manages targets similarly to SpellBook, allowing creation and management of target types.    
The `SpellBook` and `TargetGenerator` simplify spell and target handling, with each Warlock able to learn and use spells dynamically. 

## Tips for Efficiency
Although this project involves many classes, the structure of code across files is very similar. This can be simplified with file duplication and search/replace techniques to avoid repetitive typing. Here’s a guide:

1. **Duplicate Files** using `cp` in the terminal:  
   `cp file_to_be_copied.cpp new_file.cpp`  
   `cp file_to_be_copied.hpp new_file.hpp`

2. **Batch Replace** content with `sed`:  
   `sed -i s/to_remove/replace/g new_file.hpp new_file.cpp`

3. **Fine-tuning** in `vim` or your preferred editor:  
   Open the file in `vim`, highlight content with `v`, then use `:s/old/new/g` to refine specific content.
   
4. **Output checking** in terminal:   
	you have several options here.., I chose to simply compare in the terminal the output of my code `./a.out | cat -e` with the given output via the `diff <(echo "my text") <(echo "given text")`   
	if everytihing is correct, there is no feedback.. if something is not the same it repeats the differences in your terminal..    In order to check whether i used the command correctly, I copied the terminl input completely and changed a letter after having run the check in order to see whether everything sticks up.

Good luck!
