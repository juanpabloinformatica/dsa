from pprint import pprint


bucket = [[] for x in range(16)]


def testHashmap() -> None:
    for i in range(10):
        BUCKET_LENGTH = 16
    for i in range(BUCKET_LENGTH * 2):
        resultIndex = i % BUCKET_LENGTH
        bucket[resultIndex].insert(0, i * 100)


def main() -> None:
    # for i in range(0, 11):
    #     result = i % 16
    #     print(f"For i:{i} ---> {result}", end="\n")
    testHashmap()
    pprint(bucket)


if __name__ == "__main__":
    main()
