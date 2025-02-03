import datetime

def generate_receipt():
    dop = datetime.datetime.now()
    print("Enter information for the picked stock. Enter stock code 00 to finish.")
    total_cost = 0
    total_items = 0
    items_list = []

    while True:
        try:
            code = input("Enter code of stock: ")
            
            if code == '00':
                break

            price = float(input("Enter stock price: "))
            quantity = int(input("Enter quantity picked: "))

            item_total = price * quantity

            total_cost += item_total
            total_items += quantity
            items_list.append((code, quantity, item_total))

        except ValueError:
            print("Invalid input. Please enter a valid number.")



    print("="*45)
    print("\nRECEIPT:")
    print("="*45)
    
    for item in items_list:
        print("{} ... X {} ... {} лв.".format(*item))

    print(f"\nTotal Cost: ${total_cost:.2f}")
    print(dop.strftime("%Y-%m-%d %H:%M:%S"))
    print("="*45)

    while True:
        try:
            payment = float(input("Enter payment amount: "))
            break
        except ValueError:
            print("Invalid input. Please enter a valid number.")

    change = payment - total_cost

    print(f"Payment: ... ${payment:.2f}")

    if change < 0:
        print("Payment insufficient!\nCustomer lacks {} лв. to perform purchase.".format(change*-1))
    else:
        print(f"Change: ... ${change:.2f}")

generate_receipt()
