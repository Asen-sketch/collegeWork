import numpy as np

def main():
    print("task 8 - author: Vladimir Asenov\n")
    
    r, c = 10, 10
    m = np.random.randint(-999, 1000, (r, c))
    
    print("matrix C:\n", m, "\n")
    
    neg_r = (m < 0).sum(axis=1)
    neg_c = (m < 0).sum(axis=0)
    
    min_r = np.argmin(neg_r)
    min_c = np.argmin(neg_c)
    
    print("negatives by row:")
    for i, n in enumerate(neg_r):
        print(f"row {i + 1}: {n}")
    
    print("\nnegatives by column:")
    for j, n in enumerate(neg_c):
        print(f"col {j + 1}: {n}")
    
    print(f"\nrow with fewest negatives: {min_r + 1} ({neg_r[min_r]})")
    print(f"column with fewest negatives: {min_c + 1} ({neg_c[min_c]})")

if __name__ == "__main__":
    main()