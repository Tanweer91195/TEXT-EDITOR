class Node {
    constructor(value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor(){
        this.root = null;
    }

    isEmpty(){
        return this.root === null;
    }

    insert(value){
        const newNode = new Node(value);
        if(this.isEmpty()){
            this.root = newNode;
        }else {
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(root, newNode){
        if(newNode.value < root.value){
            if(root.left === null){
                root.left = newNode;
            }else{
                this.insertNode(root.left, newNode);
            }
        }else{
            if(root.right === null){
                root,right = newNode;
            }else{
                this.insertNode(root.right, newNode);
            }
        }
    }
}

const bst = new BST();
console.log(`Tree is empty?`, bst.isEmpty());

bst.insert(12);
bst.insert(5);
bst.insert(15);
bst.insert(21);
