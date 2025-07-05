# TC002: Checkout – Insufficient Funds

**Test Case ID:** TC002  
**Test Case Name:** Checkout – Insufficient Funds  
**Priority:** High  
**Type:** Functional  

## Precondition
- Logged in as `ahmed123`  
- Cart contains items
- User balance is less than cart total

## Test Steps
1. Add items to cart (total > user balance)
2. Go to "View Cart"
3. Select "Checkout"
4. Verify error handling

## Expected Results
- Checkout process starts
- System detects insufficient funds
- Appropriate error message displayed
- Cart remains unchanged
- No order created

## Actual Results
*[To be filled during testing]*

## Screenshot
`screenshots/TC002_screenshot1.png`

## Status
- [ ] Pass
- [ ] Fail
- [ ] Blocked

## Notes
- Test requires user to have insufficient balance
- Error message should be user-friendly
- Cart should not be cleared on failed checkout 