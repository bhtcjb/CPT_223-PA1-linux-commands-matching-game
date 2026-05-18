// Blake Turman

#include <iostream>
#include <cassert>
#include "LinkedList.hpp"

// workaround use 1 type for all lists - template instantiation behavior
struct Test { 
    int test; 
        
    Test(const int& test) : test(test) {} 
        
    bool operator==(const Test& other) const { 
        return test == other.test; } 

        friend std::ostream& operator<<(std::ostream& lhs, const Test& rhs) {
            return lhs << rhs.test;
    }
};

void testBasic() {
    std::cerr << "Test 1: fundamental operations - isEmpty() getSize() insert() remove()" << std::endl;

    LinkedList<Test> list;

    // test empty
    assert(list.isEmpty() == true);
    assert(list.getSize() == 0);

    // test basic insert
    assert(list.insert(Test{10}) == true);
    assert(list.insert(Test{20}) == true);
    assert(list.insert(Test{30}) == true);

    // test not empty
    assert(list.isEmpty() == false);
    assert(list.getSize() == 3);

    // test basic remove
    assert(list.remove() == Test{30});
    assert(list.remove() == Test{20});

    // test not empty
    assert(list.isEmpty() == false);
    assert(list.getSize() == 1);

    // test remove to empty
    assert(list.remove() == Test{10});
    assert(list.isEmpty() == true);
    assert(list.getSize() == 0);


    std::cerr << "PASSED" << std::endl;

}

void testPeek() {
    std::cerr << "Test 2: peek(): " << std::endl;

    LinkedList<Test> list;

    // test basic peek sequential operations
    assert(list.insert(Test{10}) == true);
    assert(list.peek() == Test{10});
    assert(list.insert(Test{20}) == true);
    assert(list.peek() == Test{20});
    assert(list.insert(Test{30}) == true);
    assert(list.peek() == Test{30});

    // test peek at index at start, middle, end, and out of range
    assert(list.peek(0) == Test{30});
    assert(list.peek(1) == Test{20});
    assert(list.peek(2) == Test{10});
    assert(list.peek(static_cast<size_t>(-1)) == Test{10});

    std::cerr << "PASSED" << std::endl;

}

void testInsert() {

    std::cerr << "Test 3: insert(): " << std::endl;

    LinkedList<Test> list;

    // test sequential insert at first index
    assert(list.insert(Test{10}, 0) == true);
    assert(list.insert(Test{20}, 0) == true);
    assert(list.insert(Test{30}, 0) == true);
    assert(list.isEmpty() == false);
    assert(list.getSize() == 3);
    assert(list.peek() == Test{30});

    // test sequential insert at middle
    assert(list.insert(Test{40}, 1) == true);
    assert(list.getSize() == 4);
    assert(list.peek(1) == Test{40});
    assert(list.peek(2) == Test{20});
    assert(list.insert(Test{50}, 1) == true);
    assert(list.getSize() == 5);
    assert(list.peek(1) == Test{50});
    assert(list.peek(2) == Test{40});
    assert(list.peek(3) == Test{20});

    // test insert at last index
    assert(list.insert(Test{60}, 4) == true);
    assert(list.getSize() == 6);
    assert(list.peek(4) == Test{60});
    assert(list.peek(5) == Test{10});

    // test sequential insert one passed last index and at out of range
    assert(list.insert(Test{70}, 6) == true);
    assert(list.getSize() == 7);
    assert(list.peek(6) == Test{70});
    assert(list.insert(Test{80}, static_cast<size_t>(-1)) == true);
    assert(list.getSize() == 8);
    assert(list.peek(static_cast<size_t>(-1)) == Test{80});


    std::cerr << "PASSED" << std::endl;

}

void testRemove() {
    std::cerr << "Test 4: remove(): " << std::endl;

    LinkedList<Test> list;

    // fill list
    assert(list.insert(Test{10}) == true);
    assert(list.insert(Test{20}) == true);
    assert(list.insert(Test{30}) == true);
    assert(list.insert(Test{40}) == true);
    assert(list.insert(Test{50}) == true);
    assert(list.insert(Test{60}) == true);
    assert(list.insert(Test{70}) == true);

    // test remove at first index
    assert(list.remove(0) == Test{70});
    assert(list.isEmpty() == false);
    assert(list.getSize() == 6);
    assert(list.peek() == Test{60});

    // test sequential remove from middle
    assert(list.remove(2) == Test{40});
    assert(list.isEmpty() == false);
    assert(list.getSize() == 5);
    assert(list.peek(2) == Test{30});
    assert(list.remove(2) == Test{30});
    assert(list.isEmpty() == false);
    assert(list.getSize() == 4);
    assert(list.peek(2) == Test{20});

    // test remove from last index and out of range
    assert(list.remove(3) == Test{10});
    assert(list.isEmpty() == false);
    assert(list.getSize() == 3);
    assert(list.peek(2) == Test{20});
    assert(list.remove(static_cast<size_t>(-1)) == Test{20});
    assert(list.isEmpty() == false);
    assert(list.getSize() == 2);
    assert(list.peek(static_cast<size_t>(-1)) == Test{50});

    // test remove until empty
    assert(list.remove(1) == Test{50});
    assert(list.remove(0) == Test{60});
    assert(list.isEmpty() == true);
    assert(list.getSize() == 0);

    std::cerr << "PASSED" << std::endl;

}

void testSearch() {
    std::cerr << "Test 5: search(): " << std::endl;

    LinkedList<Test> list;

    // fill list
    assert(list.insert(Test{10}) == true);
    assert(list.insert(Test{20}) == true);
    assert(list.insert(Test{30}) == true);
    assert(list.insert(Test{40}) == true);
    assert(list.insert(Test{50}) == true);

    // test basic search for start, middle, end, and out of range
    assert(list.search(Test{50}) == 0);
    assert(list.search(Test{30}) == 2);
    assert(list.search(Test{10}) == 4);
    assert(list.search(Test{100}) == static_cast<size_t>(-1));

    // test specific member search for start, middle, end, and out of range
    assert(list.search(&Test::test, 50) == 0);
    assert(list.search(&Test::test, 30) == 2);
    assert(list.search(&Test::test, 10) == 4);
    assert(list.search(&Test::test, 100) == static_cast<size_t>(-1));


    std::cerr << "PASSED" << std::endl;

}
    

void testPrintList () {
    std::cerr << "Test 6: printList(): " << std::endl;

    LinkedList<Test> list;

    // test print empty
    assert(list.printList() == false);

    // fill list
    assert(list.insert(Test{10}) == true);
    assert(list.insert(Test{20}) == true);
    assert(list.insert(Test{30}) == true);

    // test print not empty
    assert(list.printList() == true);
    
    std::cerr << "PASSED" << std::endl;
}



int main() {
    std::cerr << "========================================" << std::endl;
    std::cerr << "LinkedList Implementation Tests" << std::endl;
    std::cerr << "========================================" << std::endl << std::endl;
    
    testBasic();
    testPeek();
    testInsert();
    testRemove();
    testSearch();
    testPrintList();
    
    std::cerr << "========================================" << std::endl;
    std::cerr << "All tests PASSED!" << std::endl;
    std::cerr << "========================================" << std::endl;
    
    return 0;
}


