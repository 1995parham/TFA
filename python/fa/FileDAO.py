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
import io


class FileDAO(DAO.DAO):
    def __init__(self):
        super().__init__()

    def build_fa(self, input_config: io.TextIOWrapper) -> FA.FA:
        """
        build FA from your input configuration file

        :param input_config: input configuration file
        :return: FA build from given configuration file
        """

        int(input_config.readline())
        delta = int(input_config.readline())
        input_config.readline()
        transition_table = []
        for i in range(0, delta):
            transition_table.append([int(number) for number in input_config.readline().rstrip('\n').split(' ')])
        input_config.readline()
        final_states = {int(number) for number in input_config.readline().rstrip('\n').split(' ')}

        input_config.close()
        del input_config

        return FA.FA(tuple(transition_table), final_states)


def test():
    """
    Test function
    :return: nothing
    """
    file_fa = (FileDAO()).build_fa(open("test-1.txt", "r"))
    assert file_fa.validate("aabab")


if __name__ == "__main__":
    test()
