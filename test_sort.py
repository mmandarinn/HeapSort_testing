import unittest
import subprocess

# Класс, необходимый для тестирования
class TestHeapSort(unittest.TestCase):
    def RunProgram(self, input_str):
        res = subprocess.run(["./heap_sort.exe"], input=input_str, capture_output=True, text=True)
        return res.stdout.strip()

# обычная проверка сортировки на простом примере
    def test_simple(self):
        self.assertEqual(self.RunProgram("3\n5 1 2\n"),"1 2 5")

# проверка на пустой массив
    def test_empty(self):
        self.assertEqual(self.RunProgram("0\n"), "")

# проверка на массив из одного элемента
    def test_single(self):
        self.assertEqual(self.RunProgram("1\n5\n"),"5")

# проверка на массив с дубликатами
    def test_double(self):
        self.assertEqual(self.RunProgram("3\n7 5 7\n"),"5 7 7")