# <center>QUEUE</center>
A queue is logically a first in first out (FIFO or first come first serve) linear data structure. The concept of queue can be understood by our real life problems. 
For example a customer come and join in a queue to take the train ticket at the end (rear) and the ticket is issued from the front end of queue. That is, the customer who arrived first will receive the ticket first. It means the customers are serviced in the order in which they arrive at the service centre.

![Queue Image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221213113312/Queue-Data-Structures.png)

## <center>OPERATION PERFORMED ON QUEUE</center>
It is a homogeneous collection of elements in which new elements are added at one end called rear, and the existing elements are deleted from other end  called front.

The basic operations that can be performed on queue are -
1. **Insert (or add) an element to the queue (enqueue)**

**Enqueue operation** will insert (or add) an element to queue, at the rear end, by incrementing the array index.

### <CENTER> ALGORITHM FOR ENQUEUE OPERATION</CENTER>
<pre>
1. Initialize front=0 rear = –1
2. Input the value to be inserted and assign to variable “data”
3. If (rear >= SIZE)
    (a) Display “Queue overflow”   
    (b) Exit
4. Else
    (a) Rear = rear +1
5. Q[rear] = data
6. Exit
</pre>

2. **Delete (or remove) an element from a queue (dequeue)**

**Dequeqe operation** will delete (or remove) from the front end by decrementing the array index and will assign the deleted value to a variable.
### <CENTER> ALGORITHM FOR DEQUEUE OPERATION</CENTER>
<pre>
1. If (rear< front)
    (a) Front = 0, rear = –1
    (b) Display “The queue is empty”
    (c) Exit
2. Else
    (a) Data = Q[front]
3. Front = front +1
4. Exit
</pre>

<hr>

## APPLICATION OF QUEUE IN DATA STRUCTURE

1. **Task Scheduling:** Queues can be used to schedule tasks based on priority or the order in which they were received.

2. **Resource Allocation:** Queues can be used to manage and allocate resources, such as printers or CPU processing time.

3. **Batch Processing:** Queues can be used to handle batch processing jobs, such as data analysis or image rendering.

4. **Message Buffering:** Queues can be used to buffer messages in communication systems, such as message queues in messaging systems or buffers in computer networks.

5. **Event Handling:** Queues can be used to handle events in event-driven systems, such as GUI applications or simulation systems.

6. **Traffic Management:** Queues can be used to manage traffic flow in transportation systems, such as airport control systems or road networks.

7. **Operating systems:** Operating systems often use queues to manage processes and resources. For example, a process scheduler might use a queue to manage the order in which processes are executed.

8. **Network protocols:** Network protocols like TCP and UDP use queues to manage packets that are transmitted over the network. Queues can help to ensure that packets are delivered in the correct order and at the appropriate rate.

9. **Printer queues** :In printing systems, queues are used to manage the order in which print jobs are processed. Jobs are added to the queue as they are submitted, and the printer processes them in the order they were received.

10. **Web servers:** Web servers use queues to manage incoming requests from clients. Requests are added to the queue as they are received, and they are processed by the server in the order they were received.

11. **Breadth-first search algorithm:** The breadth-first search algorithm uses a queue to explore nodes in a graph level-by-level. The algorithm starts at a given node, adds its neighbors to the queue, and then processes each neighbor in turn.

## Application of Queue in real life:

1. Round robin techniques for processor scheduling is implemented using queue.
2. Printer server routines (in drivers) are designed using queues.
3. All types of customer service software (like Railway/Air ticket reservation) are designed using queue to give proper service to the customers.