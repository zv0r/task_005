from subprocess import run, PIPE
import os
import pytest

B_FILE_PATH = './bin/house'

def test_house_1():
    result = run([B_FILE_PATH], input='6 10 5 20000', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == 'NO 162500'

def test_house_2():
    result = run([B_FILE_PATH], input='3 3 2 27500', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == 'YES'

def test_house_3():
    result = run([B_FILE_PATH], input='3 3 2 27000', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == 'NO 500'

def test_house_4():
    result = run([B_FILE_PATH], input='18 20 10 0', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == 'NO 993000'

def test_house_5():
    result = run([B_FILE_PATH], input='5 5 3 100000', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == 'YES'

if __name__ == "__main__":
    pytest.main()