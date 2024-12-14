print("Auction begins")

auction_end = False
details = {}
while auction_end is False:
    name = input("Enter your name: ")
    bid = int(input("Enter your bidding amount: "))
    others = input("Enter 'Yes' if there are other bidders: ").lower()

    details.update({name: bid})

    if others == "yes":
        auction_end = False
    else:
        auction_end = True

highest_bid = 0
highest_bidder = str()
for bids in details.values():
    if bids >= highest_bid:
        highest_bid = bids

for bidders, bids in details.items():
    if bids == highest_bid:
        highest_bidder = bidders

print(f"{highest_bidder} wins with a bid of ${highest_bid}")

