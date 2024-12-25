# CPP05

This module is about exceptions in C++.
このモジュールはC++の例外についてです。  
from ex00 to ex03, the number of files and functions will increase gradually.  
ex00からex03まで、徐々にファイルや機能が増えていきます。  
you can use `make` to compile the files.
`make`コマンドを使ってファイルをコンパイルすることができます。

## ex00
This is a simple program that throws an exception.  
例外を投げる簡単なプログラムです。  
a bureaucrat has a grade from 1 to 150, and if you try to set a grade outside this range, an exception will be thrown.  
官僚には1~150までの位があり、範囲外に設定しようとした場合に例外を投げます。  

## ex01
Form class is added.  
Formクラスが追加されます。  
Form has a grade to sign and a grade to execute.  
署名するための位と実行するための位を持っています。  
If the bureaucrat's grade is lower than the grade to sign or execute, an exception will be thrown.  
官僚の位が署名するための位や実行するための位より低い場合、例外が投げられます。  

## ex02
Form class has changed to AForm class(abstract class).  
FormクラスがAFormクラス(抽象クラス)に変更されます。  
three classes are derived from the AForm class.  
AFormクラスから、以下の三つのクラスが派生します。  
- <CLASS_NAME>(<SIGN_GRADE>, <EXEC_GRADE>)
- ShrubberyCreationForm(145, 137)
- RobotomyRequestForm(72, 45)
- PresidentialPardonForm(25, 5)

## ex03
Intern class is added.  
Internクラスが追加されます。  
Intern class has a makeForm function that returns a pointer to the Form class.  
InternクラスはFormクラスへのポインタを返すmakeForm関数を持っています。  
If the form name is not found, an exception will be thrown.  
フォーム名が見つからない場合、例外が投げられます。  
