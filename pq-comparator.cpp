#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    string name;
    int age;

    Node(string n, int a) : name(n), age(a) {}
};

/* Note: If we needed this to have access to private Node fields, then
 *       we would need to add the following function declaration to the
 *       Node class above:
 *           friend ostream& operator<<(ostream& os, const Node& n);
 */
ostream& operator<<(ostream& os, const Node& n) {
    return os << "(" << n.name << ", " << n.age << ")" << endl;
}

/*NOTE: The completed examples below only consider one field of the Node class above
 *      at a time. For the HCNodePtrComp in HCNode.cpp, you will want to think about
 *      how you can adapt the examples below to consider both variables, check for
 *      ties with the count, and assign the priorities accordingly. As an exercise,
 *      you can take a look at the completed NodePtrAgeComparator and completed
 *      NodePtrNamecomparator below and, based on those, think about what the empty
 *      NodePtrAgeThenNameComparator below would look like.
 */


/* Give the higher priority to the age that is higher.
 */
struct NodePtrAgeComparator {
    bool operator()(Node*& lhs, Node*rhs) const {
        return lhs->age < rhs->age;
    }
};

/* Give the higher priority to the name that is lower alphabetically
 */
struct NodePtrNameComparator {
    bool operator()(Node*& lhs, Node*rhs) const {
        return lhs->name > rhs->name;
    }
};

/* Give the higher priority to the age that is higher. If the age's are
 * equal, then give the higher priority to the name that comes first
 * alphabetically.
 */
struct NodePtrAgeThenNameComparator {
    bool operator()(Node*& lhs, Node*rhs) const {

        // Think about how you could implement this! What would you
        // first need to check?



    }
};

/* NOTE: This uses a copy of the pq passed in, so it doesn't actually modify the original
 *       priority queue object that was passed in into the call. Know that this isn't
 *       recommended for large priority queues, as copying over the whole thing adds more
 *       computational cost. We're defining it this way so that we can easily print to
 *       demonstrate the ordering of the priority queues generated in main below.
 */
template <class Comp>
void printPQContents(priority_queue<Node*, vector<Node*>, Comp> pq) {
    Node* current;
    while (!pq.empty()) {
        current = pq.top();
        cout << (*current);
        pq.pop();
    }
}

template <class Comp>
void pushNodesOntoQueue(priority_queue<Node*, vector<Node*>, Comp>& pq, vector<Node*>& nodes) {
    vector<Node*>::iterator itr;
    for (itr = nodes.begin(); itr != nodes.end(); itr++) {
        pq.push(*itr);
    }
}

int main() {

    // Create some nodes to add to a priority queue below
    vector<Node*> nodes;
    nodes.push_back(new Node("Carl", 14));
    nodes.push_back(new Node("Diana", 17));
    nodes.push_back(new Node("Bob", 21));
    nodes.push_back(new Node("Alice", 17));
    nodes.push_back(new Node("Bob", 20));

    // Instantiate priority queue that uses the age comparator and print out the entries from highest to lowest priority
    priority_queue<Node*, vector<Node*>, NodePtrAgeComparator> ageQueue;
    pushNodesOntoQueue<NodePtrAgeComparator>(ageQueue, nodes);
    cout << "The entries in the age queue, with higher age being given higher priority:\n" << endl;
    printPQContents<NodePtrAgeComparator>(ageQueue);

    // Instantiate priority queue that uses the name comparator and print out the entries from highest to lowest priority
    priority_queue<Node*, vector<Node*>, NodePtrNameComparator> nameQueue;
    pushNodesOntoQueue<NodePtrNameComparator>(nameQueue, nodes);
    cout << "\nThe entries in the name queue, with lesser alphabetical name being given higher priority:\n" << endl;
    printPQContents<NodePtrNameComparator>(nameQueue);

    for (Node* n : nodes) {
        delete n;
    }
}
