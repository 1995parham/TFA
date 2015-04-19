# In The Name Of God
# ========================================
# [] File Name : FileDAO
#
# [] Creation Date : 20-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
__author__ = 'Parham Alvani'

from fa import FA
from fa import DAO


class FileDAO(DAO.DAO):
    def __init__(self):
        pass

    def build_fa(self, input_config):
        """
        build FA from your input configuration file

        :type input_config: str
        :param input_config: input configuration file path
        :return: FA build from given configuration file
        """

        if not isinstance(input_config, str):
            raise TypeError("input_config must be string")

        file = open(input_config, "r")
        int(file.readline())
        delta = int(file.readline())
        file.readline()
        transition_table = []
        for i in range(0, delta):
            transition_table.append([int(number) for number in file.readline().rstrip('\n').split(' ')])
        file.readline()
        final_states = [int(number) for number in file.readline().rstrip('\n').split(' ')]

        final_states = tuple(final_states)
        transition_table = tuple(transition_table)

        file.close()
        del file

        return FA.FA(transition_table, final_states)


def test():
    """
    Test function
    :return: nothing
    """
    fa = (FileDAO()).build_fa("test-1.txt")
    assert fa.validate("aabab")


if __name__ == "__main__":
    test()