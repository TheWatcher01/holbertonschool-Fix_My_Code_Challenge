###
# Sort integer arguments (ascending)
###

result = []

ARGV.each do |arg|
    # Check if the argument is an integer (positive or negative)
    next unless arg =~ /^-?\d+$/

    # Convert to integer
    i_arg = arg.to_i

    # Add directly to the list
    result << i_arg
end

# Sort the list of integers
result.sort!

# Display the result
puts result
