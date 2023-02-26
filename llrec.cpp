#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // Base case: empty list
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    // Recursive call on the rest of the list
    llpivot(head->next, smaller, larger, pivot);

    // Add current node to smaller or larger list
    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    } else {
        head->next = larger;
        larger = head;
    }

    // Set head to null to empty the original list
    head = nullptr;
}
