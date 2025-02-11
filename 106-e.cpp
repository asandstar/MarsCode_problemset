// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076995116
#include <iostream>
#include <vector>
#include <algorithm>
// 求任务最高并发数
// 扫描线/事件驱动
// 处理任务开始和结束事件
// 动态更新正在进行的任务数，记录最大值
// 1.事件定义：任务=开始事件+结束事件
// 开始事件：start?task+1:task
// 结束事件：start?task-1:task
// 2.事件排序：同时发生的先处理结束再处理开始
// 3.扫描事件：遍历排序后事件列表，维护计数器记录当前任务数
int solution(int n, std::vector<std::vector<int>> array)
{
    // create events list
    std::vector<std::pair<int, int>> events;
    for (const auto &task : array)
    {
        int start = task[0];
        int end = task[0] + task[1];
        events.push_back({start, 1});
        events.push_back({end, -1});
        // start,end is the type of event
        // 1, -1 is the code of corresponding event
    }

    // sort by time
    std::sort(events.begin(), events.end());
    int current_tasks = 0;
    int max_concurrent_tasks = 0;

    // scan events
    for (const auto &event : events)
    {
        current_tasks += event.second;
        if (current_tasks > max_concurrent_tasks)
        {
            max_concurrent_tasks = current_tasks;
        }
    }
    return max_concurrent_tasks;
}

int main()
{
    // Add your test cases here
    std::cout << (solution(2, {{1, 2}, {2, 3}}) == 2) << std::endl;
    std::cout << (solution(4, {{1, 2}, {2, 3}, {3, 5}, {4, 3}}) == 3) << std::endl;

    return 0;
}
