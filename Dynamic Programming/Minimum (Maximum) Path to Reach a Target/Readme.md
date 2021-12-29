Statement:
Given a target find minimum (maximum) cost / path / sum to reach the target.

Approach:
Choose minimum (maximum) path among all possible paths before the current state, then add value for the current state.

# routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]

Generate optimal solutions for all values in the target and return the value for the target.

