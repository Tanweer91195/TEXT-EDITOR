/*
push(element) - add
pop() - remov from the top 
peek() - get the value of the top element without removing it 
isEmpty() - Check if stack is empty 
size() - get the number of elements
print() - visualize the element in the stack
*/ 

class Stack{
    constructor(){
        this.items = [];
    };

    push(element){
        this.items.push(element);
        }

        pop(){
            return this.items.pop();
        }

        peek(){
            return this.items[this.items.length - 1];
        }

        isEmpty(){
            return this.items.length === 0;
        }

        size(){
            return this.items.length
        }

        print(){
            console.log(this.items.toString());
        }
};

const stack = new Stack();
console.log(stack.isEmpty());

stack.push(10);
stack.push(20);
stack.push(30);
stack.push(40);
stack.push(50);
stack.push(60);
console.log(stack.size());
stack.print();

console.log(stack.pop());
console.log(stack.peek());
stack.print();
