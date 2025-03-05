using System;
using System.Collections.Generic;
using System.Linq;

public class Node<T> {
    private T _value { get; private set; };
    private Node<T> _left { get; private set; };
    private Node<T> _right { get; private set; };
    

    public Node(T value) => _value = value;
 
    public void Add(T newValue)
    {
        if (newValue.CompareTo(_value) < 0)
        {
            if (_left == null)
            {
                _left = new Node<T>(newValue);
            }
            else
            {
                _left.Add(newValue);
            }
        }
        else
        {
            if (_right == null)
            {
                _right = new Node<T>(newValue);
            }
            else
            {
                _right.Add(newValue);
            }
        }
    }
    
}

public class BinaryTree<T> {
    private Node<T> _head;
}

class HelloWorld {
  static void Main() {
    Console.WriteLine("Hello World");
  }
}
