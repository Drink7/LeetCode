class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // check odd or even
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        if (maxHeapSize * minHeapSize == 0) {
            if (maxHeapSize == 0 && minHeapSize == 0) {
                minHeap.push(num);
            } else if (maxHeapSize == 0) {
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        } else {
            if (num > maxHeap.top()) {
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // check odd or even
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        double maxHeapTop = (maxHeapSize == 0) ? 0.0 : maxHeap.top();
        double minHeapTop = (minHeapSize == 0) ? 0.0 : minHeap.top();
        if ((maxHeapSize + minHeapSize) % 2 == 0) {
            return (double) (maxHeapTop + minHeapTop) / 2.0;
        } else {
            if (maxHeapSize > minHeapSize) {
                return maxHeapTop;
            } else {
                return minHeapTop;
            }
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