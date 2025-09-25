class Solution {
public:
    std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
        // 1. Add original index to each task for the result
        for (int i = 0; i < tasks.size(); i++) {
            // tasks[i] becomes {enqueueTime, processingTime, originalIndex}
            tasks[i].push_back(i); 
        }
        
        // 2. Sort tasks by enqueue time (tasks[i][0])
        std::sort(tasks.begin(), tasks.end());
        
        std::vector<int> res;
        
        // Min-Heap stores {processingTime, originalIndex}. 
        // It prioritizes by processing time, then by index for ties.
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> minHeap; 
        
        // 'time' tracks the CPU's current completion time. Initialize with the first task's start time.
        long long time = tasks[0][0]; 
        int i = 0;
        
        // Loop continues until all tasks are added (i < tasks.size()) AND the heap is empty.
        while (!minHeap.empty() || i < tasks.size()) { // *** FIX IS HERE: Changed && to || ***
            
            // Phase A: Add all available tasks
            // While there are tasks left to consider AND the current CPU time 
            // is greater than or equal to a task's enqueue time, add it to the minHeap.
            while (i < tasks.size() && time >= tasks[i][0]) {
                // Push {processingTime, originalIndex}
                minHeap.push({tasks[i][1], tasks[i][2]});
                i += 1;
            }
            
            // Phase B: Process one task or advance time
            if (!minHeap.empty()) {
                // Process the highest priority task (min processing time)
                std::pair<int, int> top = minHeap.top();
                minHeap.pop();
                
                // Update time by adding the processing time
                time += top.first;
                
                // Add the task's original index to the result
                res.push_back(top.second);
            } else if (i < tasks.size()) {
                // If the heap is empty but there are remaining tasks, 
                // the CPU must idle until the next task is available.
                // Advance time to the enqueue time of the next available task.
                time = tasks[i][0];
            }
        }
        
        return res;
    }
};
