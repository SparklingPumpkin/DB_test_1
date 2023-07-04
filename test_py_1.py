# This Python file uses the following encoding: utf-8
import openai
import sys
print("------start------")

#openai.api_key = "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"
openai.api_key = "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"


#completion = openai.ChatCompletion.create(
#    model="gpt-3.5-turbo",
#    messages=[
#        {"role": "system", "content": "You are a helpful assistant."},
#        {"role": "user", "content": "Who won the world series in 2020?"},
#        {"role": "assistant", "content": "The Los Angeles Dodgers won the World Series in 2020."},
#        {"role": "user", "content": "Where was it played?"}
#    ]
#)

question = sys.argv[1]
completion = openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    messages=[
        {"role": "system", "content": "You are a helpful assistant."},
        {"role": "user", "content": question}
    ]
)

print(completion.choices[0].message)

