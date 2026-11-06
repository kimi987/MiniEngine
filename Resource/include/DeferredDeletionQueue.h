#pragma once

#include <cstdint>
#include <memory>
#include <map>
#include <iostream>


namespace Mini
{
    struct PendingDeletion
    {
        uint64_t lastUsedFrame;
    };

    template<typename T>
    class FrameDeletionQueue
    {
    public:
        using FrameId = uint64_t;

        void Retire(FrameId lastUsedFrame, std::unique_ptr<T> resource);

        void Collect(FrameId completedFrame);

        std::size_t PendingCount() const
        {
            return pending_.size();
        }
    private:
        std::multimap<FrameId, std::unique_ptr<T>> pending_;
    };



    template<typename T>
    void FrameDeletionQueue<T>::Retire(FrameId lastUsedFrame, std::unique_ptr<T> resource)
    {
        pending_.emplace(lastUsedFrame, std::move(resource));
    }

    template<typename T>
    void FrameDeletionQueue<T>::Collect(FrameId completedFrame)
    {
        std::cout << "Collect " << completedFrame << std::endl;
        auto firstPending = pending_.upper_bound(completedFrame);

        while (firstPending != pending_.begin())
        {
            /* code */
            pending_.erase(pending_.begin());
        }
    } 
}
