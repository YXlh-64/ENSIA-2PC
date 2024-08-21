class EightPuzzle:
    def __init__(self, initial_state, goal_state, state_transition_model,path_cost=0,actions=""):
        self.state = initial_state
        self.goal_state = goal_state
        self.state_transition_model = state_transition_model
        self.actions=actions
        self.path_cost=path_cost

    def is_goal_test(self, goal_test):
        return goal_test == self.goal_state
    
    def find_empty_position(self, state):
        for i, row in enumerate(state):
            for j, cell in enumerate(row):
                if cell == 0:
                    return i, j
                
    def get_valid_actions(self, state):
        valid_actions = []
        empty_position=self.find_empty_position(state)
        for action, move_info in self.state_transition_model.items():
            new_position = [empty_position[0] + move_info[0], empty_position[1] + move_info[1]]
            if self.is_valid_position(new_position):
                valid_actions.append(action)
        return valid_actions
    
    def is_valid_position(self, position):
        row, col = position
        return 0 <= row < len(self.state) and 0 <= col < len(self.state[0])
                                                                     
    
    def apply_action(self, state, action):
        empty_row, empty_col = self.find_empty_position(state)
        new_state = copy.deepcopy(state)

        if action == "up":
            new_state[empty_row][empty_col], new_state[empty_row - 1][empty_col] = new_state[empty_row - 1][empty_col], new_state[empty_row][empty_col]
        elif action == "down":
            new_state[empty_row][empty_col], new_state[empty_row + 1][empty_col] = new_state[empty_row + 1][empty_col], new_state[empty_row][empty_col]
        elif action == "left":
            new_state[empty_row][empty_col], new_state[empty_row][empty_col - 1] = new_state[empty_row][empty_col - 1], new_state[empty_row][empty_col]
        elif action == "right":
            new_state[empty_row][empty_col], new_state[empty_row][empty_col + 1] = new_state[empty_row][empty_col + 1], new_state[empty_row][empty_col]

        return new_state
    
    def shuffle(self,num): 
        for _ in range(0,num):
            actions = self.get_valid_actions(self.state)
            #randomly choose one of the four moves
            self.state = self.apply_action(self.state,choice(actions))
    
    def expand_node(self, node):
        state = node.state
        valid_actions = self.get_valid_actions(state)
        child_nodes = []
        for action in valid_actions:
            child_state = self.apply_action(state, action)
            child_node = Node(child_state, parent=node, action=action, cost=node.cost + 1)
            child_nodes.append(child_node)
        return child_nodes
    
    def printNode(self,message,node):
        print ("Action = ",end=" ")
        print(node.action,end=" ")
        print(message,end=" ")
        print(node.state)
