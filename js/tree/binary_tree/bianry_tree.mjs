class BinaryTree {
    constructor(rootNode = null) {
        this.rootNode = rootNode;
        this.leftSubTree = null;
        this.rightSubTree = null;
    }

    getData() {
        return this.rootNode;
    }

    setData(data) {
        this.rootNode = data;
    }

    getLeftSubTree() {
        return this.leftSubTree;
    }

    getRightSubTree() {
        return this.rightSubTree;
    }

    setLeftSubTree(tree) {
        this.leftSubTree = tree;
    }

    setRightSubTree(tree) {
        this.rightSubTree = tree;
    }

    preOrderTraversal(tree) {
        if (tree == null) return;

        console.log(tree.rootNode);
        this.preOrderTraversal(tree.getLeftSubTree());
        this.preOrderTraversal(tree.getRightSubTree());
    }

    inOrderTraversal(tree) {
        if (tree == null) return;

        this.inOrderTraversal(tree.getLeftSubTree());
        console.log(tree.rootNode);
        this.inOrderTraversal(tree.getRightSubTree());
    }

    postOrderTraversal(tree) {
        if (tree == null) return;

        this.postOrderTraversal(tree.getLeftSubTree());
        this.postOrderTraversal(tree.getRightSubTree());
        console.log(tree.rootNode);
    }
}

export {BinaryTree};
