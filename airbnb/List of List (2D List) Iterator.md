### Problem statement
Create List of List (2D List) Iterator
> Leetcode #251 Flatten 2D Vector
Leetcode #341 Flatten Nested List Iterator

> For example, Given 2d vector = [ [1,2], [3], [4,5,6] ]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be:
[1,2,3,4,5,6].
• boolean hasNext() return true if there is another element in the set
• int next() return the value of the next element in the array
• void remove()
o remove the last element returned by the iterator.
o That is, remove the element that the previous next() returned.
o This method can be called only once per call to next(), otherwise an exception will be
thrown.
Removes from the underlying collection the last element returned by this iterator (optional operation).
This method can be called only once per call to next(). The behavior of an iterator is unspecified if the
underlying collection is modified while the iteration is in progress in any way other than by calling this
method.
So the remove() method actually removes the element returned from the next().