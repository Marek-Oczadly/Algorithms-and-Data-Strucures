#pragma once
#include <initializer_list>
#include <algorithm>
#include <string>


struct Event {
	std::string name;
	double start_time, end_time;
};

class GreedyAlgorithm {
	Event* const events;
	const unsigned int num_events;
public:
	GreedyAlgorithm(const std::initializer_list<Event>& event_list) :
		events(new Event[event_list.size()]), num_events(event_list.size()) {
		Event* i = events;
		for (const auto& event: event_list) {
			*i = event;
			++i;
		}
		std::sort(events, events + num_events, [](const Event& a, const Event& b) {
			return a.end_time < b.end_time;
		});
	}
};