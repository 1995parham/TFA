# In The Name Of God
# ========================================
# [] File Name : FA_test.py
#
# [] Creation Date : 18-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
from . import FA


class TestFA:
    def test_0(self):
        even_a_fa = FA.FA([
            (('b'), ('a')),
            (('a'), ('b'))
        ], {0})
        assert even_a_fa.validate("aab")
        assert not even_a_fa.validate("aaab")
        assert even_a_fa.validate("aaaab")
        assert not even_a_fa.validate("aaaaab")

    def test_1(self):
        couple_a_fa = FA.FA([
            (('b'), ('a')),
            (('a'), ())
        ], {0})
        assert couple_a_fa.validate("aabaa")
        assert not couple_a_fa.validate("ab")
