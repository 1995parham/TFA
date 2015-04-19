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
    """

    def __init__(self, transition_table, final_states):
        """
        :type transition_table: tuple
        :type final_states: tuple
        :param transition_table: FA transition table
        :param final_states: FA final states
        :return: nothing
        """

        if not isinstance(transition_table, tuple):
            raise TypeError("transition_table must be tuple")
        if not isinstance(final_states, tuple):
            raise TypeError("final_states must be tuple")
        self.transition_table = transition_table
        self.final_states = final_states

    def validate(self, w):
        """
        :type w: str
        :param w: input string
        :return: boolean indicate that FA accepts w or not
        """
        if not isinstance(w, str):
            raise TypeError("w must be string")
        w.lower()
        current_state = 1
        w_index = 0
        while w_index < len(w):
            current_state = self.transition_table[current_state - 1][ord(w[w_index]) - ord('a')]
            w_index += 1
        if self.final_states.count(current_state) > 0:
            return True
        else:
            return False


if __name__ == "__main__":
    fa = FA(((2, 1), (1, 2)), (2,))
    assert not fa.validate("aab")
    assert fa.validate("aaab")
    assert not fa.validate("aaaab")
    assert fa.validate("aaaaab")