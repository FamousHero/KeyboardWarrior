#include "../Include/KeyQueue.h"

#include <queue>
#include <chrono>

int KeyQueue::KeyQueue::getSpeed()
{
    return 0;
}

char KeyQueue::KeyQueue::popKey()
{
    char top_key = m_key_queue.front();
    m_key_queue.pop();

    return top_key;
}

std::chrono::time_point<std::chrono::duration<MILLISECONDS>> KeyQueue::KeyQueue::popKeyTiming()
{

    std::chrono::time_point<std::chrono::duration<MILLISECONDS>> top_key_timing;
    top_key_timing = m_time_queue.front();
    m_time_queue.pop();

    return top_key_timing;
}
