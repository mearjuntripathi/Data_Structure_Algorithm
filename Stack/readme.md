# <center>STACK</center> 
A stack is one of the most important and useful non-primitive linear data structure in computer science. It is an ordered collection of items into which new data items may be added/inserted and from which items may be deleted at only one end, called the top of the stack. As all the addition and deletion in a stack is done from the top of the stack, the last added element will be first removed from the stack. That is why the stack is also called Last-in-First-out (LIFO). Note that the most frequently accessible element in the stack is the top most elements, whereas the least accessible element is the bottom of the stack.

![Stack implementation ](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

<hr>

## <center>OPERATION PERFORMED ON STACK</center>

**PUSH :** <br>The process of adding (or inserting) a new element to the top of the stack is called PUSH operation. Pushing an element to a stack will add the new element at the top. After every push operation the top is incremented by one. If the array is full and no new element can be accommodated, then the stack overflow condition occurs.

### <CENTER> ALGORITHM FOR PUSH OPERATION</CENTER>
<pre>

1.If TOP = SIZE – 1, then:
    a. Display “The stack is in overflow condition”
    b. Exit

2. TOP = TOP + 1
3. STACK [TOP] = ITEM
4. Exit
</pre>

**POP :** <br> The process of deleting (or removing) an element from the top of stack is called POP operation. After every pop operation the stack is decremented by one. If there is no element in the stack and the pop operation is performed then the stack underflow condition occurs.

### <CENTER>ALGORITHM FOR POP OPERATION</CENTER>
<pre>
1. If TOP < 0 , then:
    a. Display “The stack is in Underflow condition”
    b. Exit

2. data = STACK[TOP]
3. remove the top most element
4. return data
</pre>
<hr>

## Application of Stack Data Structure: 
<br>
<ul>
<li> <b><u>Function calls and recursion:</b></u> When a function is called, the current state of the program is pushed onto the stack. When the function returns, the state is popped from the stack to resume the previous function’s execution.</li> <br>
<li> <b><u>Undo/Redo operations:</b></u> The undo-redo feature in various applications uses stacks to keep track of the previous actions. Each time an action is performed, it is pushed onto the stack. To undo the action, the top element of the stack is popped, and the reverse operation is performed.</li> <br>
<li> <b><u>Expression evaluation:</b></u> Stack data structure is used to evaluate expressions in infix, postfix, and prefix notations. Operators and operands are pushed onto the stack, and operations are performed based on the stack’s top elements.</li> <br>
<li> <b><u>Browser history:</b></u> Web browsers use stacks to keep track of the web pages you visit. Each time you visit a new page, the URL is pushed onto the stack, and when you hit the back button, the previous URL is popped from the stack.</li> <br>
<li> <b><u>Balanced Parentheses:</b></u> Stack data structure is used to check if parentheses are balanced or not. An opening parenthesis is pushed onto the stack, and a closing parenthesis is popped from the stack. If the stack is empty at the end of the expression, the parentheses are balanced.</li> <br>
<li> <b><u>Backtracking Algorithms:</b></u> The backtracking algorithm uses stacks to keep track of the states of the problem-solving process. The current state is pushed onto the stack, and when the algorithm backtracks, the previous state is popped from the stack.</li>
</ul>

## Application of Stack in real life:

<ul>
 <li>   Call center systems. </li>
 <li>   Undo and Redo mechanism in text editors. </li>
 <li>   The history of a web browser is stored in the form of a stack. </li>
 <li>   Call logs, E-mails, and Google photos in any gallery are also stored in form of a stack. </li>
 <li>   YouTube downloads and Notifications are also shown in LIFO format(the latest appears first ).</li>
 <li>   Allocation of memory by an operating system while executing a process. </li>
<ul>

