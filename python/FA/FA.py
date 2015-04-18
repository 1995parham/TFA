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
    def __init__(self, file):
        if not hasattr(file, 'read'):
            raise TypeError
        self.sigma = int(file.readline())
        self.delta = int(file.readline())