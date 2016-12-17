# In The Name Of God
# ========================================
# [] File Name : FA
#
# [] Creation Date : 19-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'


class FA:
    """
    simple class for handling finite automata

    FA class object is immutable so you cannot change
    them after building them.
    """

    def __init__(self, transition_table: list, final_states: set):
        """
        :param transition_table: FA transition table
        -------------
        |   | 1 | 2 |
        | 1 | b | a |
        | 2 | a | b |
        -------------
        [((b), (a)), ((a), (b))]
        :param final_states: FA final states
        :return: nothing
        """

        if not isinstance(transition_table, list):
            raise TypeError("transition_table must be list")
        if not isinstance(final_states, set):
            raise TypeError("final_states must be set")
        self.transition_table = []
        for state in transition_table:
            next_states = {}
            next_state = 0
            for transition in state:
                for alphabet in transition:
                    next_states[alphabet] = next_state
                next_state += 1
            self.transition_table.append(next_states)
        self.final_states = final_states
        print(self)

    def validate(self, w):
        """
        validate string with this FA

        :type w: str
        :param w: input string
        :return: boolean indicate that FA accepts w or not
        """
        if not isinstance(w, str):
            raise TypeError("w must be string")
        w.lower()
        current_state = 0
        for c in w:
            try:
                current_state = self.transition_table[current_state][c]
            except KeyError:
                return False
        if current_state in self.final_states:
            return True
        else:
            return False

    def __str__(self):
        r = ''
        i = 0
        for state in self.transition_table:
            s = 'state %d:\n' % i
            for alphabet, next_state in state.items():
                s += '\t %d -[%1s]-> %d\n' % (i, alphabet, next_state)
            i += 1
            r += s
        return r
