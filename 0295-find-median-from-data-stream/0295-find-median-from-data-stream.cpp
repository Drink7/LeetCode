class MedianFinder {
public:
    MedianFinder() {
        // two heap
        // TC: O(logn)
        // SC: O(n)        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
        } else {
            int maxHeapTop = maxHeap.top();
            if (num > maxHeapTop) {
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }

            int maxHeapSize = maxHeap.size();
            int minHeapSize = minHeap.size();
            if (abs(maxHeapSize - minHeapSize) > 1) {
                if (maxHeapSize > minHeapSize) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                } else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        double maxHeapTop = (maxHeapSize == 0) ? 0.0 : maxHeap.top();
        double minHeapTop = (minHeapSize == 0) ? 0.0 : minHeap.top();
        // odd
        if ((maxHeapSize + minHeapSize) % 2 == 1) {
            if (maxHeapSize > minHeapSize) {
                return maxHeapTop;
            } else {
                return minHeapTop;
            }
        } else {
            // even
            return (maxHeapTop + minHeapTop) / 2.0;
        }
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */