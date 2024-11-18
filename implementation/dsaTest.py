from pprint import pprint


# Hashmap *hashmap = newHashmap("number", "number");
# int keys[32];
# for (int i = 0; i < 32; i++) {
#   keys[i] = i;
# }
# for (int i = 0; i < 32; i++) {
#   // int keyValue = keys[i] * 100;
#   int *keyValue = (int *)malloc(sizeof(int));
#   *keyValue = keys[i] * 100;
#   hashmap->hashmapPut(hashmap, &keys[i], keyValue);
#   printf("\nPOINTER OF THE ARRAY IN {i} INDEX:\t%p", &keys[i]);
# }
# // for (int i = 0; i < 32; i++) {
# //   printf("\nvalue: %d", *(int *)(hashmap->array[i]));
# // }
# printf("%p", hashmap);
def testHashmap() -> None:
    BUCKET_LENGTH = 16
    bucket = [[] for x in range(16)]
    for i in range(BUCKET_LENGTH * 2):
        resultIndex = i % BUCKET_LENGTH
        print(f"Result Index Number: {i}\n Number % BUCKET_LENGTH: {resultIndex}\n")
        bucket[resultIndex].insert(0, i * 100)

    pprint(bucket)


def main() -> None:
    # for i in range(0, 11):
    #     result = i % 16
    #     print(f"For i:{i} ---> {result}", end="\n")
    testHashmap()


if __name__ == "__main__":
    main()
