Dvostruki Heap - Efficient Dual Heap Data Structure.

Dvostruki Heap is a C++ implementation of a data structure that represents a dual heap. This data structure allows for efficient removal of both the minimum and maximum elements in O(log n) time complexity. The heap is implemented as an array, offering the benefits of both a min heap and a max heap simultaneously.

Key Features
Efficient Removal: Dvostruki Heap provides fast removal of both the minimum and maximum elements, making it suitable for various applications where both extremes are important.

Balanced Structure: The structure ensures that elements on even depths are smaller than their parent but larger than their grandparent, while elements on odd depths are larger than their parent but smaller than their grandparent.

Array-Based Implementation: The heap is implemented as an array, making it memory-efficient and easy to manage.

Exception Handling: The implementation includes robust exception handling to ensure safe and reliable operation.

Functionality
Dvostruki Heap offers the following key functionalities:

Insertion: Add elements to the dual heap while maintaining the balanced property.

Removal of Minimum and Maximum: Efficiently remove both the minimum and maximum elements, each in O(log n) time complexity.

Get Minimum and Maximum: Retrieve the minimum and maximum elements without removal.

Constructor: Initialize the dual heap from an array, ensuring the dual heap property is maintained during construction.

Implementation Details
The project is implemented in C++, showcasing advanced data structure concepts for efficient dual heap management.
